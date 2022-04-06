"""
	-	object.__len__(self)
Called to implement the built-in function len(). Should return the length of the object, an integer >= 0. 
Also, an object that doesn’t define a __bool__() method and whose __len__() method returns zero is 
considered to be false in a Boolean context.

	-	object.__length_hint__(self)
Called to implement operator.length_hint(). Should return an estimated length for the object (which may 
be greater or less than the actual length). The length must be an integer >= 0. The return value may 
also be NotImplemented, which is treated the same as if the __length_hint__ method didn’t exist at all. 
This method is purely an optimization and is never required for correctness.

Note Slicing is done exclusively with the following three methods. A call like:
a[1:2] = b
is translated to
a[slice(1, 2, None)] = b
and so forth. Missing slice items are always filled in with None.

"""

