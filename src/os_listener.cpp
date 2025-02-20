#include "os_listener.h"
#include "godot_cpp/core/error_macros.hpp"

#include "godot_cpp/classes/os.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/memory.hpp"
#include "godot_cpp/core/print_string.hpp"
#include "os_event.h"

#include <cstdlib>
#include <stdlib.h>

#ifdef OS_MACOS
//
#endif

#ifdef OS_WINDOWS
#include "win32_listener.h"
#endif

#ifdef OS_LINUX
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

Error OSListener::start_listen() {
#ifdef OS_MACOS
  //
#endif

#ifdef OS_WINDOWS
  return start_listen_win32();
#endif

#ifdef OS_LINUX
  return start_listen_x11();
#endif

  WARN_PRINT_ONCE("Not implemented for this OS");
  return FAILED;
}

void OSListener::stop_listen() {
#ifdef OS_MACOS
  //
#endif

#ifdef OS_WINDOWS
  return stop_listen_win32();
#endif

#ifdef OS_LINUX
  return stop_listen_x11();
#endif

  WARN_PRINT_ONCE("Not implemented for this OS");
}

OSEvent *OSListener::get_event() {
#ifdef OS_MACOS
  //
#endif

#ifdef OS_WINDOWS
  return get_win32_event();
#endif

#ifdef OS_LINUX
  const char *x11 = getenv("DISPLAY");
  const char *wayland = getenv("WAYLAND_DISPLAY");

  if (wayland && !x11) {
    WARN_PRINT_ONCE("Native Wayland doesn't support global shortcuts");
    return nullptr;
  }

  return get_x11_event();
#endif

  WARN_PRINT_ONCE("Not implemented for this OS");
  return nullptr;
}

void OSListener::_bind_methods() {
  ClassDB::bind_static_method("OSListener", D_METHOD("get_singleton"),
                              &OSListener::get_singleton);

  ClassDB::bind_method(D_METHOD("start_listen"), &OSListener::start_listen);
  ClassDB::bind_method(D_METHOD("stop_listen"), &OSListener::stop_listen);
  ClassDB::bind_method(D_METHOD("get_event"), &OSListener::get_event);
}

OSListener::OSListener() {}

OSListener::~OSListener() {}