#include "win32_listener.h"

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
      event->code = keyboard_event->vkCode;
      events.push_back(event);
    } else if (wParam == WM_KEYUP) {
      event->type = OSEvent::KEY_RELEASE;
      event->code = keyboard_event->vkCode;
      events.push_back(event);
    }
  }

  return CallNextHookEx(NULL, number_code, wParam, lParam);
}
