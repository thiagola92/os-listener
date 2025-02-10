#include "x11_listener.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xcb/xcb.h>
#include <xcb/xinput.h>

const char *xinput_name = "XInputExtension";

// Not thread-safe.
xcb_connection_t *connection = nullptr;

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

  if (!_is_xinput_present()) {
    return ERR_UNAVAILABLE;
  }

  return _start_listen_events();
}

void stop_listen_x11() {
  if (connection) {
    xcb_disconnect(connection);
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

  xcb_ge_generic_event_t *generic_event = (xcb_ge_generic_event_t *)event;
  OSEvent *os_event = memnew(OSEvent);

  switch (generic_event->event_type) {
  case XCB_INPUT_RAW_KEY_PRESS:
    os_event->type = OSEvent::KEY_PRESS;
    os_event->code = ((xcb_input_raw_key_press_event_t *)event)->detail;

    free(event);

    return os_event;
  case XCB_INPUT_RAW_KEY_RELEASE:
    os_event->type = OSEvent::KEY_RELEASE;
    os_event->code = ((xcb_input_raw_key_release_event_t *)event)->detail;

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