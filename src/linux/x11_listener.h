#ifndef X11LISTENER_H
#define X11LISTENER_H

#include <godot_cpp/classes/input_event.hpp>

using namespace godot;

Error start_listen_x11();

void stop_listen_x11();

InputEvent *get_x11_event();

bool _is_xinput_present();

Error _start_listen_events();

Key _get_godot_keycode(uint32_t keysym);

#endif