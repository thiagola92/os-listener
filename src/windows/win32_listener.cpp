#include "win32_listener.h"
#include "key_mapping_win32.h"

#include <godot_cpp/classes/input_event_key.hpp>
#include <list>

HHOOK handle_hook;

std::list<InputEvent *> events;

Error start_listen_win32() {
  handle_hook =
      SetWindowsHookEx(WH_KEYBOARD_LL, _on_event, GetModuleHandle(NULL), 0);

  if (!handle_hook) {
    return ERR_CANT_CONNECT;
  }

  return OK;
}

void stop_listen_win32() {
  if (handle_hook) {
    UnhookWindowsHookEx(handle_hook);
    handle_hook = nullptr;
  }
}

InputEvent *get_win32_event() {
  MSG msg;

  // Don't use GetMessage() because it will block until message arrive.
  PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);

  if (events.size() > 0) {
    InputEvent *e = events.front();
    events.pop_front();
    return e;
  }

  return nullptr;
}

LRESULT CALLBACK _on_event(int number_code, WPARAM wParam, LPARAM lParam) {
  if (number_code == HC_ACTION) {
    KBDLLHOOKSTRUCT *keyboard_event = (KBDLLHOOKSTRUCT *)lParam;
    InputEventKey *event_key = memnew(InputEventKey);

    Key keycode = _get_godot_keycode(keyboard_event->vkCode);
    bool is_key_pressed = (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
    bool is_alt_pressed = (keyboard_event->flags & LLKHF_ALTDOWN) == LLKHF_ALTDOWN;
    bool is_shift_pressed = keycode == Key::KEY_SHIFT;
    bool is_ctrl_pressed = keycode == Key::KEY_CTRL;
    bool is_meta_pressed = keycode == Key::KEY_META;

    event_key->set_keycode(keycode);
    event_key->set_pressed(is_key_pressed);
    event_key->set_alt_pressed(is_alt_pressed);
    event_key->set_shift_pressed(is_shift_pressed);
    event_key->set_ctrl_pressed(is_ctrl_pressed);
    event_key->set_meta_pressed(is_meta_pressed);

    events.push_back(event_key);
  }

  return CallNextHookEx(NULL, number_code, wParam, lParam);
}

/*
I would love to make an "#include" that would give me access to code from:
   https://github.com/godotengine/godot/blob/master/platform/windows/key_mapping_windows.cpp
   https://github.com/godotengine/godot/blob/master/core/os/keyboard.cpp

But it's not included in "godot-cpp", so I made this adaptation from the Godot.
It's not good but the other option is to copy and adapt many files from Godot
project, which would increase the complexity of the project.
*/
Key _get_godot_keycode(DWORD vkcode) {
  const Key k = vk_map[vkcode];
  if (k) {
    return k;
  }

  return Key::KEY_NONE;
}
