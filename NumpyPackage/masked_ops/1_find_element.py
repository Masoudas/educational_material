"""
The where method is used for searching a numpy array. If no element is found, an empty tuple is returned, otherwise
the first element of the tuple are the true indexes.

For 2D matrices, the second dimension of the returned tuple is the column
"""
import numpy as np

arr = np.array((1, 2, 3, 2))
print(np.where(arr == 2))	# The where method returns the true indexes.

arr = np.array([[1, 2], [3, 4]])
loc = np.where(arr < 3)
print(loc[0], loc[1])	# Returns [0, 0] and [0, 1]
	