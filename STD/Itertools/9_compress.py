"""
To compress a data set (with boolean vectors for example,) we use the compress iterator. Again, this is to
avoid copying the list, which is also cool.

Compared to Filter, with Filter we need to pass a predicate, but here we just pass the True or False directly.
"""

from itertools import compress

letters = [1, 2, 3, 4]

selectors = [True, False, True, False]

for i in compress(letters, selectors):
	print(i)