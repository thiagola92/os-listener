#ifndef X11LISTENER_H
#define X11LISTENER_H

#include "os_event.h"

using namespace godot;

godot::Error start_listen_x11();

void stop_listen_x11();

godot::OSEvent *get_x11_event();

bool _is_xinput_present();

godot::Error _start_listen_events();

#endif