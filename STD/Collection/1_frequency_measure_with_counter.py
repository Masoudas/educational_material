"""
The Counter method returns a dictionary, which contains the frequency of each item (the very famous method of 
calculating the frequency.)

The most common method returns the most common method as well. We can specify n as well, which returns the n most
common methods.
"""
from collections import Counter

ls = [1, 1, 2, 4, 2, 3, 1, 1]
measure = Counter(ls)
print(measure)

print(measure.most_common(1))
print(measure.most_common(2))
