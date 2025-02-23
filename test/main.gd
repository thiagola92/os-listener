extends Node2D


func _ready() -> void:
	assert(OSListener.get_singleton().start_listen() == OK)
	
	# Make sure to be in the right layout while testing.
	var layout: int = DisplayServer.keyboard_get_current_layout()
	print(DisplayServer.keyboard_get_layout_name(layout))


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
