extends Node2D


func _ready() -> void:
	assert(OSListener.get_singleton().start_listen() == OK)


func _input(event: InputEvent) -> void:
	if event is InputEventKey:
		if event.pressed:
			printt("i >> key pressed", event.keycode)
		else:
			printt("i >> key released", event.keycode)


func _process(_delta: float) -> void:
	var e: InputEvent = OSListener.get_singleton().get_event()
	
	if e is InputEventKey and e.pressed:
		printt("p >> key pressed", e.keycode)
	elif e is InputEventKey and not e.pressed:
		printt("p >> key released", e.keycode)
