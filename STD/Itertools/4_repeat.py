"""
For repeating a value
"""
from itertools import repeat

rpt = repeat("2", times=10)
print(next(rpt))
print(next(rpt))
print(next(rpt))
print(next(rpt))
print(next(rpt))
print(next(rpt))

# From standard
squares = map(pow, range(10), repeat(2))	# Stops when the shortest iterator is exhausted. Infinitely
													# returns two. Hence, creates all popwer twos of the given
													# numbers.
print(list(squares))
# [0**2, 1**2, 2**2, 3**2, 4**2, ...]