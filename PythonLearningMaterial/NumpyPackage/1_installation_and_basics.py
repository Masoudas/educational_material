"""
To install numpy, simply use 
(env_name) $ pip install python

Numpy is a module for working with multi-dimensional arrays. To create a basic array, use ndarray:
	-	It is a table of elements (usually numbers), all of the same type, indexed by a tuple of positive 
		integers.
	-	In NumPy dimensions are called axes. The number of axes is rank.
	-	NumPy’s array class is called ndarray. It is also known by the alias array.

Notice that array is used for directly creating an array from a list, whereas ndarray for creating an array from
a set of properties.

Note that a 1 dimensional array has exactly one dimension, and as such that axis is zero. As we move forward,
the dimensions increase starting from column.

Me: The default values of a numpy array is zero it seems. Also, always recall that the right-most number is the 
number of columns.

"""
import numpy as np

# First array I've created after two and a half years.
arr = np.ndarray(shape=[3,2], dtype=float)
print(arr)

# From default values. Notice that array is a function that returns an ndarray
arr2 = np.array([[1, 2, 3], [4, 5, 6]])
print(arr2)


