"""
An important mistake regarding passing arguments is to pass a default empty mutable collection, like a string.
This implies that the collection is shared among all instances of the function. Why? Because function arguments
are formed when the function is defined in python, and not when it's run (so we don't create different instances
of the default argument.)

This is a major source of headache, and should be avoided.

If we want a mutable default, first set it to None, then check for None
"""

def append(val, l=[]):	# The list is created only one time when creating the function, not everytime the function
					# is called.
	l.append(val)
	return l

print(append(1)) # [1]
print(append(2)) # Oops! It prints [1, 2]

def correct_append(val, l=None):
	if not l:
		l = []
	
	l.append(val)
	return l

	
