#ifndef OSEVENT_H
#define OSEVENT_H

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"

namespace godot {

class OSEvent : public RefCounted {
  GDCLASS(OSEvent, RefCounted)

protected:
  static void _bind_methods();

public:
  enum {
    KEY_PRESS = 1,
    KEY_RELEASE = 2,
  };

  int type = 0;
  int code = 0;

  int get_type();
  int get_code();

  OSEvent();
  ~OSEvent();
};

} // namespace godot

#endif
