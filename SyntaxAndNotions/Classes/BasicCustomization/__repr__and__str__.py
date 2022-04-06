#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
	-	object.__repr__(self)
Called by the repr() built-in function to compute the “official” string representation of an object. If at all 
possible, this should look like a valid Python expression that could be used to recreate an object with the same 
value (given an appropriate environment). If this is not possible, a string of the form <...some useful 
description...> should be returned. The return value must be a string object. If a class defines __repr__() but 
not __str__(), then __repr__() is also used when an “informal” string representation of instances of that class 
is required.

This is typically used for debugging, so it is important that the representation is information-rich and unambiguous.

	-	object.__str__(self)
Called by str(object) and the built-in functions format() and print() to compute the “informal” or nicely printable 
string representation of an object. The return value must be a string object.

This method differs from object.__repr__() in that there is no expectation that __str__() return a valid Python 
expression: a more convenient or concise representation can be used.

The default implementation defined by the built-in type object calls object.__repr__().
"""

class Point:
	def __repr__(self):
		return "The value is (1, 1). Called in the absence of a __str__method. Used normally for debugging."
	
	def __str__(self):
		return "This is a point. Has priority when it comes to the print method, and conversion to string."

print(Point())