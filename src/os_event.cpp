#include "os_event.h"

#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/property_info.hpp"

using namespace godot;

int OSEvent::get_type() { return type; }

int OSEvent::get_code() { return code; }

void OSEvent::_bind_methods() {
  ClassDB::bind_method(D_METHOD("get_type"), &OSEvent::get_type);
  ClassDB::bind_method(D_METHOD("get_code"), &OSEvent::get_code);

  ADD_PROPERTY(PropertyInfo(Variant::INT, "type"), "", "get_type");
  ADD_PROPERTY(PropertyInfo(Variant::INT, "code"), "", "get_code");

  BIND_CONSTANT(KEY_PRESS);
  BIND_CONSTANT(KEY_RELEASE);
}

OSEvent::OSEvent() {}

OSEvent::~OSEvent() {}