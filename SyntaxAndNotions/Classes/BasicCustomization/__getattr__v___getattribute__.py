"""
Me: Note that by a class attribute, we mean both data and methods.

	-	object.__getattr__(self, name)
Called when the default attribute access fails with an AttributeError (either __getattribute__() raises an 
AttributeError because name is not an instance attribute or an attribute in the class tree for self; or 
__get__() of a name property raises AttributeError). This method should either return the (computed) attribute 
value or raise an AttributeError exception.

Note that if the attribute is found through the normal mechanism, __getattr__() is not called. (This is an 
intentional asymmetry between __getattr__() and __setattr__().) This is done both for efficiency reasons and 
because otherwise __getattr__() would have no way to access other attributes of the instance. Note that at least 
for instance variables, you can fake total control by not inserting any values in the instance attribute 
dictionary (but instead inserting them in another object). See the __getattribute__() method below for a way to 
actually get total control over attribute access.

	-	object.__getattribute__(self, name)
Called unconditionally to implement attribute accesses for instances of the class. If the class also defines 
__getattr__(), the latter will not be called unless __getattribute__() either calls it explicitly or raises an 
AttributeError. This method should return the (computed) attribute value or raise an AttributeError exception. 
In order to avoid infinite recursion in this method, its implementation should always call the base class method 
with the same name to access any attributes it needs, for example, object.__getattribute__(self, name).

Note This method may still be bypassed when looking up special methods as the result of implicit invocation via 
language syntax or built-in functions. See Special method lookup.
For certain sensitive attribute accesses, raises an auditing event object.__getattr__ with arguments obj and name.

Some points from the Internet and my tests:
	-	getattribute is always called first, regardless of whether or not an attribute exists. The following test
	clearly demonstrates that:

#####
class Foo:
	def __init__(self) -> None:
		self.b = 10

	def __getattr__(self, name):
		print("Inside __getattr__")
	
	def __getattribute__(self, name):
		print("Inside __getattribute__")
		raise AttributeError
Foo().a
Foo().b
#####

	-	__getattr__ and __getattribute__ are essentially used for overloading the dot operator. __getattr__ is
		called only once all other methods have failed to return a value.

	-	Because __getattribute__ is the first method we go through to access a property, overloading it incorrectly
	leads to infinite recursion. For example, below, we try to return self.__dict__[name]. But note that the dot
	operator itself tries to access __dict__ using the __getattribute__ method. As such, we'd have an infinite
	recursion here. So __getattribute__ must not use any other property (or method of the object.)

#####
class Foo(object):
    def __init__(self, a):
        self.a = 1

    def __getattribute__(self, attr):
        try:
            return self.__dict__[attr]
        except KeyError:
            return 'default'
#####

"""


