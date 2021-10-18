"""
Me: Just like C++, we can implement operators as stannd-alone operators. See the Lib/operator section of the 
standard library.

To implement comparisons for a class, according to the standard, we can do as follows:

Given a class defining one or more rich comparison ordering methods, this class decorator supplies the rest. This 
simplifies the effort involved in specifying all of the possible rich comparison operations:

The class must define one of __lt__(), __le__(), __gt__(), or __ge__(). In addition, the class should supply an 
__eq__() method (Me: Hence, defining one, defines others. Also, speed as discussed below is important.)

These methods can return any value, so if the comparison operator is used in a Boolean context (e.g., in the 
condition of an if statement), Python will call bool() on the value to determine if the result is true or false.

By default, object implements __eq__() by using is, returning NotImplemented in the case of a false comparison: 
True if x is y else NotImplemented. For __ne__(), by default it delegates to __eq__() and inverts the result unless 
it is NotImplemented. There are no other implied relationships among the comparison operators or default 
implementations; for example, the truth of (x<y or x==y) does not imply x<=y. To automatically generate ordering 
operations from a single root operation, see functools.total_ordering().

There are no swapped-argument versions of these methods (to be used when the left argument does not support the 
operation but the right argument does); rather, __lt__() and __gt__() are each other’s reflection, __le__() and 
__ge__() are each other’s reflection, and __eq__() and __ne__() are their own reflection. If the operands are of 
different types, and right operand’s type is a direct or indirect subclass of the left operand’s type, the 
reflected method of the right operand has priority, otherwise the left operand’s method has priority. Virtual 
subclassing is not considered.

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