#include "os_listener.h"

#include <cstdlib>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/core/print_string.hpp>
#include <stdlib.h>

#if defined(OS_WINDOWS)
#include "win32_listener.h"
#elif defined(OS_LINUX)
#include "x11_listener.h"
// #include "wayland_listener.h"
#endif

using namespace godot;

// https://refactoring.guru/design-patterns/singleton/cpp/example
OSListener *OSListener::singleton = nullptr;

OSListener *OSListener::get_singleton() {
  if (singleton == nullptr) {
    singleton = memnew(OSListener);
  }

  return singleton;
}

#if defined(OS_WINDOWS)
Error OSListener::start_listen() { return start_listen_win32(); }
#elif defined(OS_LINUX)
Error OSListener::start_listen() { return start_listen_x11(); }
#else
Error OSListener::start_listen() {
  WARN_PRINT_ONCE("OSShortcut not implemented for this OS/Web");
  return OK;
}
#endif

#if defined(OS_WINDOWS)
void OSListener::stop_listen() { stop_listen_win32(); }
#elif defined(OS_LINUX)
void OSListener::stop_listen() { stop_listen_x11(); }
#else
void OSListener::stop_listen() {}
#endif

#if defined(OS_WINDOWS)
InputEvent *OSListener::get_event() { return get_win32_event(); }
#elif defined(OS_LINUX)
InputEvent *OSListener::get_event() {
  const char *x11 = getenv("DISPLAY");
  const char *wayland = getenv("WAYLAND_DISPLAY");

  if (wayland && !x11) {
    WARN_PRINT_ONCE("OSShortcut doesn't support native Wayland");
    return nullptr;
  }

  return get_x11_event();
}
#else
InputEvent *OSListener::get_event() { return nullptr; }
#endif

void OSListener::_bind_methods() {
  ClassDB::bind_static_method("OSListener", D_METHOD("get_singleton"),
                              &OSListener::get_singleton);

  ClassDB::bind_method(D_METHOD("start_listen"), &OSListener::start_listen);
  ClassDB::bind_method(D_METHOD("stop_listen"), &OSListener::stop_listen);
  ClassDB::bind_method(D_METHOD("get_event"), &OSListener::get_event);
}

OSListener::OSListener() {}

OSListener::~OSListener() {}