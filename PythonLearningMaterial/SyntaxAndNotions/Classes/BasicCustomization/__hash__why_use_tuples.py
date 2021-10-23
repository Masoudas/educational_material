"""
Me: Here's a thought. If two instances have the same hash, and their __eq__ method returns true, when used inside a
a dictionary, they'd be replaced in that dictionary (recall that dicts use hash, and then comparison methods).

I thought using tuples takes care of this, but it doesn't, because has is calculated with respect to the content of
the tuple, and not its instance (I thought having a new instance means having a new hash value.) Using the tuple
is good, because the hash function takes only one argument.

As such, we must not return the same hash if we want different instances to be placed in different places inside
a dictionary.
"""
class hashable_eq:
	def __eq__(self, o):
		return True

	def __hash__(self):
		return hash((1,))

dict1 = {hashable_eq(): 1, hashable_eq(): 2}	# Duplicate key.

print(dict1)

class unique_hash_eq:
	def __eq__(self, o):
		return True

	def __hash__(self):
		return hash((1, id(self)))

dict2 = {unique_hash_eq(): 1, unique_hash_eq(): 2}	# No duplicate keys now
print(dict2)
