extends Node2D


func _ready() -> void:
	var o = OSListener.get_singleton()
	print(o.start_listen() == OK)
	print(o)


func _process(_delta: float) -> void:
	var e: OSEvent = OSListener.get_singleton().get_event()
	
	if e and e.type == e.KEY_PRESS:
		print("key pressed")
	elif e and e.type == e.KEY_RELEASE:
		print("key released")
