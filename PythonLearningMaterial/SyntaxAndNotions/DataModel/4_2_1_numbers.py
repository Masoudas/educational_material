"""
These are created by numeric literals and returned as results by arithmetic operators and arithmetic built-in 
functions. Numeric objects are immutable; once created their value never changes (Me: Definitely didn't know that). 
Python numbers are of course strongly related to mathematical numbers, but subject to the limitations of numerical 
representation in computers.

The string representations of the numeric classes, computed by __repr__() and __str__(), have the following 
properties:

	-	They are valid numeric literals which, when passed to their class constructor, produce an object having the 
		value of the original numeric.
	-	The representation is in base 10, when possible.
	-	Leading zeros, possibly excepting a single zero before a decimal point, are not shown.
	-	Trailing zeros, possibly excepting a single zero after a decimal point, are not shown.
	-	A sign is shown only when the number is negative.

Python distinguishes between integers, floating point numbers, and complex numbers.

Me: Despite these being objects, they still behave as value types, because they're immutable, and the refernce
is copied into the function, but we can't change the address to the object.
"""
def f(x):
	x = 20
x = 10
f(x)
print(x)	# Still prints 10

addr1 = id(x)
x = 20
addr2 = id(x)

print(addr1 == addr2)	# Prints false of course