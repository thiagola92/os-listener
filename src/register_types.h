#ifndef OSLISTENER_REGISTER_TYPES_H
#define OSLISTENER_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_module(ModuleInitializationLevel p_level);
void uninitialize_module(ModuleInitializationLevel p_level);

#endif // OSLISTENER_REGISTER_TYPES_H