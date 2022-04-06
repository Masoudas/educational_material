"""
It's possible to define properties in Python. These properties can have getter, setter and deleter methods.

Intelligent people don't use the delete property, but I brought it here in any case.
"""

class C:
	def __init__(self):
		self._x = None

	@property
	def x(self):	# x is the name of the property
		"""I'm the 'x' property."""
		return self._x

	@x.setter
	def x(self, value):
		self._x = value

	@x.deleter
	def x(self):
		del self._x

c = C()
c.x = 10
print(c.x)

del c.x