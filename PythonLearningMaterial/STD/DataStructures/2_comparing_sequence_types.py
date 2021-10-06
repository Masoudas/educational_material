"""
We can use comparison operators directly with the sequence types. The comparison is lexicographical.

If two items to be compared are themselves sequences of the same type, the lexicographical comparison is 
carried out recursively.

If no comparison exists, a TypeError is raised.
"""

print("ABC" < "ABCD")	# True
print([1, 2, 3] < [4, 5, 6])	# True
print([1, 2, 3] < [0, 4, 4])	# False

print([1, 2, [3, 4]] < [2, 3, [4, 5]])	# True