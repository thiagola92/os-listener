#include "win32_listener.h"

HHOOK handle_hook;

OSEvent *last_event = nullptr;

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

  if (last_event) {
    memdelete(last_event);
    last_event = nullptr;
  }

  if (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return last_event;
}

LRESULT CALLBACK _on_event(int number_code, WPARAM wParam, LPARAM lParam) {
  if (number_code == HC_ACTION) {
    KBDLLHOOKSTRUCT *keyboard_event = (KBDLLHOOKSTRUCT *)lParam;

    last_event = memnew(OSEvent);

    if (wParam == WM_KEYDOWN) {
      last_event->type = OSEvent::KEY_PRESS;
      last_event->code = keyboard_event->vkCode;
    } else if (wParam == WM_KEYUP) {
      last_event->type = OSEvent::KEY_RELEASE;
      last_event->code = keyboard_event->vkCode;
    }
  }

  return CallNextHookEx(NULL, number_code, wParam, lParam);
}
