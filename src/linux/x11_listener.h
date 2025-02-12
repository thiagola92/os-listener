#ifndef X11LISTENER_H
#define X11LISTENER_H

#include "os_event.h"

using namespace godot;

Error start_listen_x11();

void stop_listen_x11();

OSEvent *get_x11_event();

bool _is_xinput_present();

Error _start_listen_events();

uint32_t _get_keycode(uint32_t keysym);

#endif