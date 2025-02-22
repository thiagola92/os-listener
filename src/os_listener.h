#ifndef OSLISTENER_H
#define OSLISTENER_H

#include <godot_cpp/classes/input_event.hpp>

namespace godot {

class OSListener : public Object {
  GDCLASS(OSListener, Object)

private:
  static OSListener *singleton;

  OSListener();
  ~OSListener();

protected:
  static void _bind_methods();

public:
  static OSListener *get_singleton();

  Error start_listen();
  void stop_listen();
  InputEvent *get_event();
};

} // namespace godot

#endif