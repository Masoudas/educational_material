"""
object.__del__(self)
Called when the instance is about to be destroyed. This is also called a finalizer or (improperly) a destructor. If 
a base class has a __del__() method, the derived class's __del__() method, if any, must explicitly call it to 
ensure proper deletion of the base class part of the instance.

It is possible (though not recommended!) for the __del__() method to postpone destruction of the instance by 
creating a new reference to it. This is called object resurrection. It is implementation-dependent whether 
__del__() is called a second time when a resurrected object is about to be destroyed; the current CPython 
implementation only calls it once.

It is not guaranteed that __del__() methods are called for objects that still exist when the interpreter exits.

Note del x doesn't directly call x.__del__() - the former decrements the reference count for x by one, and the 
latter is only called when x's reference count reaches zero.
"""

class S:
	def __del__(self):
		"""Finalize method"""
		print("Inside the finalizer method")

s = S()
del s # Both decrementing references to s, and now that it reaches zero, calls __del__

s1 = S()	# Apparently, this is not guaranteed to be executed when the interpreter is about to exit.
