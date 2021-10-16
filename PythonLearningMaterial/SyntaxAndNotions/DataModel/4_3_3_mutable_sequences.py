"""
	Mutable sequences
Mutable sequences can be changed after they are created. The subscription and slicing notations can be used as the 
target of assignment and del (delete) statements (me: unlike strings, tuples, etc). (Me: Also recall that mutable
objects are not hashable, and as such, can't be used in hash based types, like dictionaries)

There are currently two intrinsic mutable sequence types:

	-	Lists
	The items of a list are arbitrary Python objects. Lists are formed by placing a comma-separated list of 
	expressions in square brackets. (Note that there are no special cases needed to form lists of length 0 or 1.)

	-	Byte Arrays
	A bytearray object is a mutable array. They are created by the built-in bytearray() constructor. Aside from 
	being mutable (and hence unhashable), byte arrays otherwise provide the same interface and functionality as 
	immutable bytes objects.

The extension module array provides an additional example of a mutable sequence type, as does the collections module.
"""

