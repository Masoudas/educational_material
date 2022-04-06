"""
Cycles through an iterator over and over again. Used for example in a switching scenario.
"""
from itertools import cycle

counter = cycle([1, 2])

print(next(counter))
print(next(counter))
print(next(counter))
print(next(counter))
print(next(counter))
print(next(counter))


