#ifndef WIN32LISTENER_H
#define WIN32LISTENER_H

#include "os_event.h"

#include <windows.h>

using namespace godot;

Error start_listen_win32();

void stop_listen_win32();

OSEvent *get_win32_event();

LRESULT CALLBACK _on_event(int number_code, WPARAM wParam, LPARAM lParam);

int _get_godot_keycode(DWORD vkcode);

#endif