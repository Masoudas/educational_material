"""
The properties of ndarray provide some of the fundamental information we seek.
"""
import numpy as np

arr = np.ndarray([2, 3], dtype=float)
print("Number of dimensions is: ", arr.ndim)
print("Shape of the array is: ", arr.shape)
print("Array size (or total number of elements: ", arr.size)