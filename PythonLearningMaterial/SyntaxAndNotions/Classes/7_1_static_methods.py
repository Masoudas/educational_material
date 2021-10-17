"""
A static method does not receive an implicit first argument. A static method can be called either on the class 
(such as C.f()) or on an instance (such as C().f()). Moreover, they can be called as regular functions (such as f()).
(ME: not outside the class, but rather inside it.)

Static methods in Python are similar to those found in Java or C++. 
"""

class C:
	@staticmethod
	def f(arg1, arg2):
		pass

