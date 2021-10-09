"""
We can use comparison operators directly with the sequence types. The comparison is lexicographical.

If two items to be compared are themselves sequences of the same type, the lexicographical comparison is 
carried out recursively.

If no comparison exists, a TypeError is raised.

Me: Notice that the same story holds for equality comparisons. That is, equality is recursive, and applies to the
sub-elements as well, as shown below.
"""

print("ABC" < "ABCD")	# True
print([1, 2, 3] < [4, 5, 6])	# True
print([1, 2, 3] < [0, 4, 4])	# False

print([1, 2, [3, 4]] < [2, 3, [4, 5]])	# True

print([1, 2, [3, 4]] == [1, 2, [3, 4]])	# Comparison is recursive, and [3,4] is compared for equality. If reference
										# was checked, this would not have returned true.
print([1, 2, [3, 4]] == [1, 2, [4, 3]])	# Returns false

print((('a', 1), 2) == ((('a', 1), 2)))	# Comparing tuples.