"""
This one is interesting. It allows us to chain iterables together, to get a unified iterable.

This is far better than concatenating lists for example.
"""

from itertools import chain

iter = chain([1, 2, 3], [4, 5, 6])

print(list(iter))