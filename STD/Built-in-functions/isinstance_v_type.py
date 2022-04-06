"""
	-	isinstance(object, classinfo)
Return True if the object argument is an instance of the classinfo argument, or of a (direct, indirect, or virtual) 
subclass thereof. If object is not an object of the given type, the function always returns False. If classinfo is 
a tuple of type objects (or recursively, other such tuples) or a Union Type of multiple types, return True if 
object is an instance of any of the types. If classinfo is not a type or tuple of types and such tuples, a 
TypeError exception is raised.

Me: It's recommended to use this function for type check rather than type(object) == type, because this one takes
into consideration subclasses as well.


	-	class type(name, bases, dict, **kwds)
With one argument, return the type of an object. The return value is a type object and generally the same object as 
returned by object.__class__.

With three arguments, it returns a new instance of the class, but who cares!
"""
class Base:
	pass 

class Derived(Base):
	pass

print(type(Base()), Base().__class__, type(Derived()))		# Returns type is instance, which means it's an 
															# instance! But class returns the name of the class.
															# Odd that type returns whether something is an instancee
															# or a class!

print(isinstance(Derived(), Base))	# So derived is an instance of base too.

