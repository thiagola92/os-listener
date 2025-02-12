#include "x11_listener.h"

#include <xcb/xcb.h>
#include <xcb/xcb_keysyms.h>
#include <xcb/xinput.h>

const char *xinput_name = "XInputExtension";

xcb_connection_t *connection = nullptr;
xcb_key_symbols_t *keysyms = nullptr;

// Because xcb_input_event_mask_t doesn't work.
typedef struct Mask {
  xcb_input_device_id_t deviceid;
  uint16_t mask_len;
  xcb_input_xi_event_mask_t mask;
} Mask;

Error start_listen_x11() {
  if (connection) {
    return ERR_ALREADY_IN_USE;
  }

  connection = xcb_connect(NULL, NULL);

  if (xcb_connection_has_error(connection)) {
    xcb_disconnect(connection);
    connection = nullptr;
    return ERR_CANT_CONNECT;
  }

  keysyms = xcb_key_symbols_alloc(connection);

  if (!_is_xinput_present()) {
    connection = nullptr;
    return ERR_UNAVAILABLE;
  }

  return _start_listen_events();
}

void stop_listen_x11() {
  if (connection) {
    xcb_key_symbols_free(keysyms);
    xcb_disconnect(connection);

    keysyms = nullptr;
    connection = nullptr;
  }
}

OSEvent *get_x11_event() {
  if (!connection) {
    return nullptr;
  }

  xcb_generic_event_t *event = xcb_poll_for_event(connection);

  if (!event) {
    return nullptr;
  }

  uint32_t raw_keycode;
  xcb_keysym_t keysym;
  xcb_ge_generic_event_t *generic_event = (xcb_ge_generic_event_t *)event;
  OSEvent *os_event = memnew(OSEvent);

  switch (generic_event->event_type) {
  case XCB_INPUT_RAW_KEY_PRESS:
    raw_keycode = ((xcb_input_raw_key_press_event_t *)event)->detail;
    keysym = xcb_key_symbols_get_keysym(keysyms, raw_keycode, 0);

    os_event->type = OSEvent::KEY_PRESS;
    os_event->code = _get_godot_keycode(keysym);

    free(event);

    return os_event;
  case XCB_INPUT_RAW_KEY_RELEASE:
    raw_keycode = ((xcb_input_raw_key_press_event_t *)event)->detail;
    keysym = xcb_key_symbols_get_keysym(keysyms, raw_keycode, 0);

    os_event->type = OSEvent::KEY_RELEASE;
    os_event->code = _get_godot_keycode(keysym);

    free(event);

    return os_event;
  }

  free(event);
  memdelete(os_event);

  return nullptr;
}

bool _is_xinput_present() {
  xcb_query_extension_cookie_t cookie =
      xcb_query_extension(connection, strlen(xinput_name), xinput_name);

  xcb_query_extension_reply_t *reply =
      xcb_query_extension_reply(connection, cookie, NULL);

  if (!reply || !reply->present) {
    free(reply);
    return false;
  }

  free(reply);

  return true;
}

Error _start_listen_events() {
  const xcb_setup_t *setup = xcb_get_setup(connection);
  xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);
  xcb_screen_t *screen = iter.data;

  xcb_input_xi_event_mask_t events =
      (xcb_input_xi_event_mask_t)(XCB_INPUT_XI_EVENT_MASK_RAW_KEY_PRESS |
                                  XCB_INPUT_XI_EVENT_MASK_RAW_KEY_RELEASE);

  Mask mask = {XCB_INPUT_DEVICE_ALL_MASTER, 1, events};

  xcb_void_cookie_t cookie = xcb_input_xi_select_events(
      connection, screen->root, 1, (const xcb_input_event_mask_t *)&mask);

  xcb_generic_error_t *error = xcb_request_check(connection, cookie);

  if (error) {
    free(error);
    return ERR_CONNECTION_ERROR;
  }

  xcb_flush(connection);

  return OK;
}

/*
I would love to make an "#include" that would give me access to code from:
   https://github.com/godotengine/godot/blob/master/platform/linuxbsd/x11/key_mapping_x11.cpp
   https://github.com/godotengine/godot/blob/master/core/os/keyboard.cpp

But it's not included in "godot-cpp", so I made this adaptation from the Godot.
It's not good but the other option is to copy and adapt many files from Godot
project, which would increase the complexity of the project.
*/
int _get_godot_keycode(xcb_keysym_t keysym) {
  if (keysym >= 0x20 && keysym < 0x7E) {  // ASCII, maps 1-1
    if (keysym > 0x60 && keysym < 0x7B) { // Lowercase ASCII.
      return keysym - 32;
    } else {
      return keysym;
    }
  }

  return 0;
}