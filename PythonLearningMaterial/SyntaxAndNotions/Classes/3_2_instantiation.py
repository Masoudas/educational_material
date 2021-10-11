"""
Class instantiation uses function notation. Just pretend that the class object is a parameterless function that 
returns a new instance of the class. For example (assuming the above class):

x = MyClass()
creates a new instance of the class and assigns this object to the local variable x.

The instantiation operation (“calling” a class object) creates an empty object. Many classes like to create objects 
with instances customized to a specific initial state. Therefore a class may define a special method named 
__init__(), like this:

def __init__(self):
    self.data = []

When a class defines an __init__() method, class instantiation automatically invokes __init__() for the newly-created 
class instance. So in this example, a new, initialized instance can be obtained by:

x = MyClass()

Of course, the __init__() method may have arguments for greater flexibility. In that case, arguments given to the 
class instantiation operator are passed on to __init__(). For example,

class Complex:
    def __init__(self, realpart, imagpart):
        self.r = realpart
        self.i = imagpart

x = Complex(3.0, -4.5)

Note from me: it's possible to delete an attribute of a class using the delete operator, which would leave no trace
of it anywhere.
"""

class c:
	i = 10

print(c.i)

## Abalfazl!
del c.i 
print(c.i)
