"""
In deep hierarchies, two problems arise:
    -   Because the subclasshook method is inherited, we get a problem, in that in A<-B and A<-C, then C is returned as a child of B and vice versa
    -   We need to call the superclass's subclasshook to ensure that we check for the properties of base and this class.

To remedy the first problem, we check that this the instance of the class that uses the method as follows:

if cls is not THIS_CLASS:
    return False    # Some people here return NotImplementedError, but I prefer returning   
                    # false, not to stop the code from execution.

One other thing is that the classes at the end of the hierachy (like B and C here) must always return False. Because, their subclass check must always return False, because they don't have any class. A worry was that as such isinstance(C(),C) may return False (below), but thankfully, that's not the case!

For the second one, I can't think of any solution other extracting the conditions and putting them in a staticmethod.
"""
from abc import ABC

class A(ABC):
    @classmethod
    def __subclasshook__(cls, subcls):
        if cls is not A:
            return False
        return A.__subclasshook__checks__(subcls)

    @staticmethod
    def __subclasshook__checks__(subcls):
        return hasattr(subcls, 'a')

class B(A):
    a: int = 10
    @classmethod
    def __subclasshook__(cls, subcls):
        if cls is not B:
            return False
        return False

class C(A):
    a: int = 10
    @classmethod
    def __subclasshook__(cls, subcls):
        if cls is not C:
            return False
        return False

print(isinstance(A(), A))
print(isinstance(C(), A))
print(isinstance(B(), A))
print(isinstance(B(), C))

print(isinstance(C(), C))
print(isinstance(B(), B))

