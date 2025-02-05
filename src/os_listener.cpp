#include "os_listener.h"
#include "godot_cpp/core/error_macros.hpp"

#include "godot_cpp/classes/os.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/memory.hpp"
#include "godot_cpp/core/print_string.hpp"
#include "os_event.h"

#include <cstdlib>

#ifdef OS_MACOS
//
#elif OS_WINDOWS
//
#elif OS_LINUX
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
  WARN_PRINT_ONCE("Not implemented for this OS");
  return FAILED;
#elif OS_WINDOWS
  WARN_PRINT_ONCE("Not implemented for this OS");
  return FAILED;
#elif OS_LINUX
  return start_listen_x11();
#else
  WARN_PRINT_ONCE("Not implemented for this OS");
  return FAILED;
#endif
}

void OSListener::stop_listen() {
#ifdef OS_MACOS
  WARN_PRINT_ONCE("Not implemented for this OS");
#elif OS_WINDOWS
  WARN_PRINT_ONCE("Not implemented for this OS");
#elif OS_LINUX
  stop_listen_x11();
#else
  WARN_PRINT_ONCE("Not implemented for this OS");
#endif
}

OSEvent *OSListener::get_event() {
#ifdef OS_MACOS
  WARN_PRINT_ONCE("Not implemented for this OS");
  return nullptr;
#elif OS_WINDOWS
  WARN_PRINT_ONCE("Not implemented for this OS");
  return nullptr;
#elif OS_LINUX
  if (!OS::get_singleton()->get_environment("WAYLAND_DISPLAY").is_empty()) {
    // return get_wayland_event();
  }

  return get_x11_event();
#else
  WARN_PRINT_ONCE("Not implemented for this OS");
  return nullptr;
#endif
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