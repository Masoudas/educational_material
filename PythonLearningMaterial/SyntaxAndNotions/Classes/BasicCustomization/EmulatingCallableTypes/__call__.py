"""
	-	object.__call__(self[, args...])¶
Called when the instance is “called” as a function; if this method is defined, x(arg1, arg2, ...) roughly 
translates to type(x).__call__(x, arg1, ...).


"""
class callable:
	def __call__(self) -> None:
		print("I'm being called")

callable()()	# One for construction and one for execution.