"""
	-	Static method objects
Static method objects provide a way of defeating the transformation of function objects to method objects described 
above. A static method object is a wrapper around any other object, usually a user-defined method object. When a 
static method object is retrieved from a class or a class instance, the object actually returned is the wrapped 
object, which is not subject to any further transformation. Static method objects are also callable. Static method 
objects are created by the built-in staticmethod() constructor.

	-	Class method objects
A class method object, like a static method object, is a wrapper around another object that alters the way in which 
that object is retrieved from classes and class instances. Class method objects are created by the built-in 
classmethod() constructor. (See my documentation in the Classes section)
"""