"""
A class can implement certain operations that are invoked by special syntax (such as arithmetic operations or 
subscripting and slicing) by defining methods with special names. This is Python’s approach to operator overloading, 
allowing classes to define their own behavior with respect to language operators. For instance, if a class defines 
a method named __getitem__(), and x is an instance of this class, then x[i] is roughly equivalent to 
type(x).__getitem__(x, i). Except where mentioned, attempts to execute an operation raise an exception when no 
appropriate method is defined (typically AttributeError or TypeError).

Setting a special method to None indicates that the corresponding operation is not available. For example, if a 
class sets __iter__() to None, the class is not iterable, so calling iter() on its instances will raise a 
TypeError (without falling back to __getitem__()).

As these methods are class specific, I put the rest of this section in the class documentation.
"""

class No_Addition:
	def __add__(self, other) -> None:
		pass