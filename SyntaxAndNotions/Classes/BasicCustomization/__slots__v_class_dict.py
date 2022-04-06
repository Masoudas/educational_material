"""
In Python, every class can have instance attributes. By default Python uses a dict to store an object’s instance 
attributes. This is really helpful as it allows setting arbitrary new attributes at runtime.

However, for small classes with known attributes it might be a bottleneck. The dict wastes a lot of RAM. Python 
can’t just allocate a static amount of memory at object creation to store all the attributes. Therefore it sucks a 
lot of RAM if you create a lot of objects (I am talking in thousands and millions). Still there is a way to 
circumvent this issue. It involves the usage of __slots__ to tell Python not to use a dict, and only allocate space 
for a fixed set of attributes. Here is an example with and without __slots__.

To prevent the creation of a __dict__, you must inherit from object and all classes in the inheritance must declare 
__slots__ and none of them can have a '__dict__' entry.

On a sidenote, you might want to give PyPy a try. It does all of these optimizations by default.

Small caveat, you should only declare a particular slot one time in an inheritance tree. For example:
class Base:
    __slots__ = 'foo', 'bar'

class Right(Base):
    __slots__ = 'baz', 

class Wrong(Base):
    __slots__ = 'foo', 'bar', 'baz'        # redundant foo and bar
"""
class MyClass(object):
    def __init__(self, name, identifier):
        self.name = name
        self.identifier = identifier

class MyClassWithSlots(object):
    __slots__ = ['name', 'identifier']
    def __init__(self, name, identifier):
        self.name = name
        self.identifier = identifier

from sys import getsizeof

print("Size of MyClass is:", getsizeof([MyClass("", "") for i in range(1000)]), 
    "and size of MyClassWithSlots is:", getsizeof([MyClassWithSlots("", "") for i in range(1000)]))

try:
    MyClassWithSlots("","").__dict__
except AttributeError:
    print("Does not have a dictionary.")