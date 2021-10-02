"""
Using these methods, we can create arrays with filled elements. As such, we can also use full, empty and random
to create an array.

We can also use linspace to create an array of linear elements.
"""
import numpy as np

# Create an array and fill it with a particular value
arr = np.full([3, 1], 5.0)	

arr1 = np.empty([2, 3], np.float64)

rand_arr = np.random.random([4, 2])

print("Even elements of the array are: ", np.linspace(0, 6, 2))
