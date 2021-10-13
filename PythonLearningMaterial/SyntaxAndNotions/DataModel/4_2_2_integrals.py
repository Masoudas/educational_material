"""
These represent elements from the mathematical set of integers (positive and negative).

There are two types of integers:

	-	Integers (int)
These represent numbers in an unlimited range, subject to available (virtual) memory only. For the purpose of shift
and mask operations, a binary representation is assumed, and negative numbers are represented in a variant of 2’s 
complement which gives the illusion of an infinite string of sign bits extending to the left.

Booleans (bool)
These represent the truth values False and True. The two objects representing the values False and True are the only 
Boolean objects. The Boolean type is a subtype of the integer type, and Boolean values behave like the values 0 and 
1, respectively, in almost all contexts, the exception being that when converted to a string, the strings "False" or 
"True" are returned, respectively.

The rules for integer representation are intended to give the most meaningful interpretation of shift and mask 
operations involving negative integers.
"""
x = 1
z = 0B101	# Binary
y = 0xFF
print(f'{x << 1:b}', z, y)

y  = b'101' # Literal byte representation, which is useful?
print(y, bytes(x))