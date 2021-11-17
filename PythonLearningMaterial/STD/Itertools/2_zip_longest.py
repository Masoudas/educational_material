"""
zip has the property that the generator that it generates ends at the shortest of the two. We can however use
zip_longest from itertools to stop at the longest. As such, the elements that don't have a corresponding value
are set to None.
"""
from itertools import zip_longest

iter_short = zip(range(3), range(2))
# [(0,0), (1,1)]

iter_long = zip_longest(range(3), range(2))
# [(0,0), (1,1), (2, None)]