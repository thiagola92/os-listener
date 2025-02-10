extends Node2D


func _ready() -> void:
	print(OSListener.get_singleton().start_listen() == OK)


func _process(_delta: float) -> void:
	var e: OSEvent = OSListener.get_singleton().get_event()
	
	if e and e.type == e.KEY_PRESS:
		printt(">> key pressed", e.code)
	elif e and e.type == e.KEY_RELEASE:
		printt(">> key released", e.code)
