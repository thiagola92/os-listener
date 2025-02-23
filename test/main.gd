extends Node2D


func _ready() -> void:
	assert(OSListener.get_singleton().start_listen() == OK)


func _input(event: InputEvent) -> void:
	if event is InputEventKey:
		if event.pressed:
			printt(event)
		else:
			printt(event)


func _process(_delta: float) -> void:
	var event: InputEvent = OSListener.get_singleton().get_event()
	
	if event is InputEventKey and event.pressed:
		printt(event)
	elif event is InputEventKey and not event.pressed:
		printt(event)
