"""
This one is interesting. It returns the first element for which the predicate is not satisfied. In other words,
it drops while! So, the iterator actually returns FROM the point the predicate is not satisfied.

Take while does the opposite. It returns the elements from where the predicate is satisfied.

Note that in both cases, if the first element is not satisfied, then that is returned, so it does not look for
a place where the constraint is satisfied for example in the second case.
"""
from itertools import dropwhile, takewhile

ls = [1, 2, 3, 4, 5]

point = dropwhile(lambda x: x < 4, ls)
print(next(point)) # Prints 4.

point = takewhile(lambda x: x < 4, ls)
print(next(point)) # Prints 1.
