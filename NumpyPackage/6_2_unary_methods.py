"""
We can, at the same time, use the min, max, sum, and other ops on arrays as well.

It's also possible to calculate the sin, cos and other values of all elements as well. These are however 
stand-alone functions
"""

import numpy as np

arr = np.array([[1, 2, 3], [4, 5, 6]])

print(arr.max(axis=0))	# Maximum on each column
print(arr.mean(axis=1))	# Mean of each row
print(arr.cumsum(axis=1))	# Cummulative sum of each row

print(np.sin(arr))