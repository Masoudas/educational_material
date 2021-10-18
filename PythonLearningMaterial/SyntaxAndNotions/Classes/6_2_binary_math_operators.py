"""
These are:

object.__add__(self, other)
object.__sub__(self, other)
object.__mul__(self, other)
object.__matmul__(self, other)			-	For @. Means matrix multiplication.
object.__truediv__(self, other)
object.__floordiv__(self, other)		-	For //, or floor division 
object.__mod__(self, other)				
object.__divmod__(self, other)			-	
object.__pow__(self, other[, modulo])
object.__lshift__(self, other)
object.__rshift__(self, other)
object.__and__(self, other)
object.__xor__(self, other)
object.__or__(self, other)

We also have the same operators but with r, like __radd__. These methods are called to implement the binary 
arithmetic operations with reflected (swapped) operands. hese functions are only called if the left operand 
does not support the corresponding operation, and the operands are of different types. For instance, to evaluate 
the expression x - y, where y is an instance of a class that has an __rsub__() method, y.__rsub__(x) is called if x.__sub__(y) returns NotImplemented
"""