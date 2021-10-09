"""
To implement comparisons for a class, according to the standard, we can do as follows:

Given a class defining one or more rich comparison ordering methods, this class decorator supplies the rest. This 
simplifies the effort involved in specifying all of the possible rich comparison operations:

The class must define one of __lt__(), __le__(), __gt__(), or __ge__(). In addition, the class should supply an 
__eq__() method (Me: Hence, defining one, defines others. Also, speed as discussed below is important.)

Note: While this decorator makes it easy to create well behaved totally ordered types, it does come at the cost of 
slower execution and more complex stack traces for the derived comparison methods. If performance benchmarking 
indicates this is a bottleneck for a given application, implementing all six rich comparison methods instead is 
likely to provide an easy speed boost.

Note: This decorator makes no attempt to override methods that have been declared in the class or its superclasses. 
Meaning that if a superclass defines a comparison operator, total_ordering will not implement it again, even if the 
original method is abstract.
"""
class Student:
    def _is_valid_operand(self, other):
        return (hasattr(other, "lastname") and
                hasattr(other, "firstname"))

    def __eq__(self, other):
        print("Using comparison method")
        if not self._is_valid_operand(other):
            return NotImplemented
        return ((self.lastname.lower(), self.firstname.lower()) ==
                (other.lastname.lower(), other.firstname.lower()))

    def __lt__(self, other):
        if not self._is_valid_operand(other):
            return NotImplemented
        return ((self.lastname.lower(), self.firstname.lower()) <
                (other.lastname.lower(), other.firstname.lower()))

    # An initializer
    def __init__(self, fn, ln) -> None:
        self.firstname = fn
        self.lastname = ln

S1 = Student("a", "b"); S2 = Student("c", "d")
if S1 == S2:    # Prints using comparison method
    pass