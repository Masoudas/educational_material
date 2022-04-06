"""
	-	Immutable sequences
An object of an immutable sequence type cannot change once it is created. (If the object contains references to 
other objects, these other objects may be mutable and may be changed; however, the collection of objects directly 
referenced by an immutable object cannot change.)

The following types are immutable sequences:

		-	Strings
	A string is a sequence of values that represent Unicode code points. All the code points in the range 
	U+0000 - U+10FFFF can be represented in a string. Python doesn’t have a char type; instead, every code point in 
	the string is represented as a string object with length 1. The built-in function ord() converts a code point 
	from its string form to an integer in the range 0 - 10FFFF; chr() converts an integer in the range 0 - 10FFFF to 
	the corresponding length 1 string object. str.encode() can be used to convert a str to bytes using the given 
	text encoding, and bytes.decode() can be used to achieve the opposite.

		-	Tuples
	The items of a tuple are arbitrary Python objects. Tuples of two or more items are formed by comma-separated 
	lists of expressions. A tuple of one item (a ‘singleton’) can be formed by affixing a comma to an expression 
	(an expression by itself does not create a tuple, since parentheses must be usable for grouping of expressions). 
	An empty tuple can be formed by an empty pair of parentheses.

		-	Bytes
	A bytes object is an immutable array. The items are 8-bit bytes, represented by integers in the range 
	0 <= x < 256. Bytes literals (like b'abc') and the built-in bytes() constructor can be used to create bytes 
	objects. Also, bytes objects can be decoded to strings via the decode() method.
"""