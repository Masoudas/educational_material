"""
We consider some standard python types:

	-	None
This type has a single value. There is a single object with this value. This object is accessed through the built-in 
name None. It is used to signify the absence of a value in many situations, e.g., it is returned from functions that 
don’t explicitly return anything. Its truth value is false. (Me: i.e, a check for none is done as 'if none', and we
needn't write 'if none is None')

	-	NotImplemented
This type has a single value. There is a single object with this value. This object is accessed through the built-in 
name NotImplemented. Numeric methods and rich comparison methods should return this value if they do not implement 
the operation for the operands provided. (The interpreter will then try the reflected operation, or some other 
fallback, depending on the operator.) It should not be evaluated in a boolean context.

Changed in version 3.9: Evaluating NotImplemented in a boolean context is deprecated. While it currently evaluates 
as true, it will emit a DeprecationWarning. It will raise a TypeError in a future version of Python
"""

class HasCompare:
	def __add__(self, other):
		return NotImplemented
	
	def __radd__(self, other):
		return NotImplemented

	def __eq__(self, other):
		return NotImplemented # In this context, returns False, which is Ok, because the objects don't have an
							  # equal method, and as such, are not equal! This appears to be going extince though.

print(HasCompare() == HasCompare())	# For boolean, it evaluates to false!
print(HasCompare() + HasCompare())
