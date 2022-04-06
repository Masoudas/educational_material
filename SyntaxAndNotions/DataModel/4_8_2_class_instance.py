"""
A class instance is created by calling a class object. A class instance has a namespace implemented as a dictionary 
which is the first place in which attribute references are searched. When an attribute is not found there, and the 
instance's class has an attribute by that name, the search continues with the class attributes. If a class attribute 
is found that is a user-defined function object, it is transformed into an instance method object whose __self__ 
attribute is the instance. Static method and class method objects are also transformed; If no class attribute is found, 
and the object's class has a __getattr__() method, that is called to satisfy the lookup.

Attribute assignments and deletions update the instance's dictionary, never a class's dictionary. If the class has 
a __setattr__() or __delattr__() method, this is called instead of updating the instance dictionary directly.

Class instances can pretend to be numbers, sequences, or mappings if they have methods with certain special names. 

Special attributes: __dict__ is the attribute dictionary; __class__ is the instance's class.
"""

class S:
	static = 10
	
	@classmethod
	def cMethod():
		pass

	def __init__(self):
		self.instance = 20 

print(S().__class__, S.__name__)	# Prints <class __main__.S at 0x7fd2454a5590> and 'S'
print(S().__dict__)	# This would be the instance dictionary, or "{'instance': 20}"
print(S.__dict__) # This would be the static attributes (including methods) 
				  # {'__module__': '__main__', 'cMethod': <classmethod object at 0x7f34cf95c6d0>, 'static': 10, '__doc__': 
				  # None, '__init__': <function __init__ at 0x7f34cf9591d0>}