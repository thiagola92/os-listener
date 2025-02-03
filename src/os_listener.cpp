#include "os_listener.h"
#include "godot_cpp/core/error_macros.hpp"
#include "x11_listener.h"

#include "godot_cpp/classes/os.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/memory.hpp"
#include "godot_cpp/core/print_string.hpp"
#include "os_event.h"
#include <cstdlib>

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
  if (OS::get_singleton()->get_name() == String("Linux")) {
    return start_listen_x11();
  } else {
    WARN_PRINT_ONCE("Failed to identify OS");
  }

  return FAILED;
}

void OSListener::stop_listen() {
  if (OS::get_singleton()->get_name() == String("Linux")) {
    return stop_listen_x11();
  } else {
    WARN_PRINT_ONCE("Failed to identify OS");
  }
}

OSEvent *OSListener::get_event() {
  if (OS::get_singleton()->get_name() == String("Linux")) {
    return get_x11_event();
  } else {
    WARN_PRINT_ONCE("Failed to identify OS");
  }

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