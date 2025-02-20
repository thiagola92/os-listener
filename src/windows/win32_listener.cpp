#include "win32_listener.h"
#include "key_mapping_win32.h"

#include <list>

HHOOK handle_hook;

std::list<OSEvent *> events;

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

OSEvent *get_win32_event() {
  MSG msg;

  // Don't use GetMessage() because it will block until message arrive.
  PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);

  if (events.size() > 0) {
    OSEvent *e = events.front();
    events.pop_front();
    return e;
  }

  return nullptr;
}

LRESULT CALLBACK _on_event(int number_code, WPARAM wParam, LPARAM lParam) {
  if (number_code == HC_ACTION) {
    KBDLLHOOKSTRUCT *keyboard_event = (KBDLLHOOKSTRUCT *)lParam;

    OSEvent *event = memnew(OSEvent);

    if (wParam == WM_KEYDOWN) {
      event->type = OSEvent::KEY_PRESS;
      event->code = _get_godot_keycode(keyboard_event->vkCode);
      events.push_back(event);
    } else if (wParam == WM_KEYUP) {
      event->type = OSEvent::KEY_RELEASE;
      event->code = _get_godot_keycode(keyboard_event->vkCode);
      events.push_back(event);
    }
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
int _get_godot_keycode(DWORD vkcode) {
    const int k = (int)vk_map[vkcode];
    if (k) {
        return k;
    }

    return 0;
}
