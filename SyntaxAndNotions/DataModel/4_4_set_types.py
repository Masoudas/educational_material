"""
	-	Set types
These represent unordered, finite sets of unique, immutable objects. As such, they cannot be indexed by any 
subscript. However, they can be iterated over, and the built-in function len() returns the number of items in a set. 
Common uses for sets are fast membership testing, removing duplicates from a sequence, and computing mathematical 
operations such as intersection, union, difference, and symmetric difference. (ME: Recall that sets are hash-based,
and as such, we can only use hashable types with them.)

For set elements, the same immutability rules apply as for dictionary keys. Note that numeric types obey the normal 
rules for numeric comparison: if two numbers compare equal (e.g., 1 and 1.0), only one of them can be contained in 
a set.

There are currently two intrinsic set types:

	-	Sets
These represent a mutable set. They are created by the built-in set() constructor and can be modified afterwards by 
several methods, such as add().

	-	Frozen sets
These represent an immutable set. They are created by the built-in frozenset() constructor. As a frozenset is 
immutable and hashable, it can be used again as an element of another set, or as a dictionary key.
"""
frozen_set = frozenset(["a", "b", "c"])	
#frozen_set.add() We can't add to a frozen set.

non_froze_set = set(["a", "b", "c"])
non_froze_set.add("d")
