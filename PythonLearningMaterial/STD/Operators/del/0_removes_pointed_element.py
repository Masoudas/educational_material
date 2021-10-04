"""
Well, delete removes the element passed to it, and we can essentially delete anything in python. Consider the 
following intuitive examples:

a = 10
del a	# Deletes this integer from memory.

a = [1, 2, 3]
del a[1]	# Deletes a[1], and the list becomes [1, 3]

del a[:2]	# Deletes all elements, but keeps the list. The list becomes []
del a		# Now deletes a itself.	
"""