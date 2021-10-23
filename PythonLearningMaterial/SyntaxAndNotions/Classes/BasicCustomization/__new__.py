"""
	-	object.__new__(cls[, ...])
Called to create a new instance of class cls.__new__() is a static method (special-cased so you need not declare 
it as such) that takes the class of which an instance was requested as its first argument. The remaining arguments 
are those passed to the object constructor expression (the call to the class). The return value of __new__() should 
be the new object instance (usually an instance of cls).

Typical implementations create a new instance of the class by invoking the superclass's __new__() method using 
super().__new__(cls[, ...]) with appropriate arguments and then modifying the newly-created instance as necessary 
before returning it.

If __new__() is invoked during object construction and it returns an instance of cls, then the new instance's 
__init__() method will be invoked like __init__(self[, ...]), where self is the new instance and the remaining 
arguments are the same as were passed to the object constructor.

If __new__() does not return an instance of cls, then the new instance's __init__() method will not be invoked.

__new__() is intended mainly to allow subclasses of immutable types (like int, str, or tuple) to customize instance 
creation. It is also commonly overridden in custom metaclasses in order to customize class creation.

Usually it's uncommon to override __new__ method, but some times it is required if you are writing APIs or 
customizing class or instance creation or abstracting something using classes.
"""
class Base:
	def __init__(self):
		print("Calling the base class init method")		
		self.__x = 5 

class Derived(Base):
	def __new__(cls):	# The __init__ method will be called after this method is called.
		instance = super().__new__()	# Create the superclass part.
		instance.__x = 20	# Customize it.

		return instance # Return the super-class, to wrap the derived class around it.

print(isinstance(Derived(), Base))