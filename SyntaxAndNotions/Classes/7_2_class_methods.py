"""
A class method receives the class as an implicit first argument, just like an instance method receives the instance. 
To declare a class method, use this idiom given below. Me: As such, class methods are static constructors.
"""

class S:
	@classmethod
	def f(cls, v1):
		return S(v1, 10)

	def __init__(self, v1, v2):
		self.v1 = v1 
		self.v2 = v2


instance = S.f()