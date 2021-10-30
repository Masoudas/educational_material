"""
One can implement the generic class syntax as specified by PEP 484 (for example List[int]) by defining a special 
method:

	-	classmethod object.__class_getitem__(cls, key)
Return an object representing the specialization of a generic class by type arguments found in key.

This method is looked up on the class object itself, and when defined in the class body, this method is implicitly 
a class method. 

Note, this mechanism is primarily reserved for use with static type hints, other usage is discouraged.
"""

class my_list:
	def __class_getitem__(cls, key):
		return "Don't use this for dynamic access!"

print(my_list[0])