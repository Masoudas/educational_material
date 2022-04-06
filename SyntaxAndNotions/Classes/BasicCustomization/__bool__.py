"""
Called to implement truth value testing and the built-in operation bool(); should return False or True. When this 
method is not defined, __len__() is called, if it is defined, and the object is considered true if its result is 
nonzero. If a class defines neither __len__() nor __bool__(), all its instances are considered true.

Note from me: A list is considered True if it has non-zero length, not if it's defined. As such, it's kind of 
bizzare that writing 'if var' returns False for an empty list.

Note: If in python2.x, we should set the __nonzero__ method equal to this method.
"""
class BoolConvertible:
	def __bool__(self):
		return False
	# __nonzero__ = __bool__ This should be done for python2.x

convertible = BoolConvertible()
if not convertible:
	print("The class always converts to false.")


if not [] and [1, 2, 3]:
	print("An empty list is false and a non-empty list is true.")