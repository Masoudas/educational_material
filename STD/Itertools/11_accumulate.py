"""
To accumulate an iterable. We can pass various functions to our accumulate function. 

Justlike C++, the operators header provides the operators we need to perform our tasks.
"""

from itertools import accumulate
from operator import mul

result = accumulate([1, 2, 3], mul)

print(next(result))
print(next(result))
