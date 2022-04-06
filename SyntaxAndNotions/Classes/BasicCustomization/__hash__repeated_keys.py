"""
Do duplicate frozensets and tuples have the same hash? And as such are duplicate keys. The answer is yes.

Me: In essence, don't use your types in dicts or sets, unless you've overriden eq and hash.
"""
s1 = (1, 2, 3, )
s2 = (1, 2, 3, )

dict1 = {s1 : 1, s2 : 2}	# Duplicate key

print(dict1)	