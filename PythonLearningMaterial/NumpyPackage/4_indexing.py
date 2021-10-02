"""
Beside the usuall bracket indexing of an array, we can:
	slice: Just like lists in python, NumPy arrays can be sliced. As arrays can be multidimensional, you need to 
		   specify a slice for each dimension of the array.
	boolean indexing: We can slice with true and false as well.

"""
import numpy as np

arr = np.array([1, 2, 3, 4, 5, 6])

print(arr[0:5:2])	# Even elements, as start:end:step
print(arr[arr > 2])	# Boolean indexing

arr_2d = np.array([[1, 2, 3], [4, 5, 6]])
print(arr_2d[:2, ::2])	# The even elements of each row
