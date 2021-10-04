"""
Packing is the operation of assiging elements to a tuple. Unpacking is the reverse, and is about openning the tuple.
"""

p = 1,
u = p

p = 1, 2, 3
u1, u2, u3 = p

u1, u2 = p	# Incorrect unpacking. Requires the same number of elements.