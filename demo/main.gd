extends Container


func _ready() -> void:
	assert(OSListener.get_singleton().start_listen() == OK)
	
	# Make sure to be in the right layout while testing.
	var layout: int = DisplayServer.keyboard_get_current_layout()
	print(DisplayServer.keyboard_get_layout_name(layout))


func _input(event: InputEvent) -> void:
	if event is InputEventKey:
		printt("GODOT", event)
		
		$Label.text = "GODOT => %s" % event.as_text_keycode()
 

func _process(_delta: float) -> void:
	var event: InputEvent = OSListener.get_singleton().get_event()
	
	if event is InputEventKey:
		printt("OS   ", event)
		
		$Label.text = "OS => %s" % event.as_text_keycode()
