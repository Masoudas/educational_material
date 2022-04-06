"""
Creats a counter to infinity (pretty much like range, except for infinity)

Step can be a float as well as start.
"""
import itertools

counter = itertools.count(1, 10)	# Creates an infinite counter.
print(next(counter))

data = [1, 2, 3, 4]

iter_with_index = zip(itertools.count(), data)	# Cool! This is valid, because zip ends on the shortest iterator.

