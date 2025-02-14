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
	var e: OSEvent = OSListener.get_singleton().get_event()
	
	if e and e.type == e.KEY_PRESS:
		printt("p >> key pressed", e.code)
	elif e and e.type == e.KEY_RELEASE:
		printt("p >> key released", e.code)
