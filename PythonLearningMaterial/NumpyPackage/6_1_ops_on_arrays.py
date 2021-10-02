"""
We can perform several basic operations on arrays, including -=, +=, *=, etc. We can also directly transpose the
array using the T operator.

To turn a single row array into a single column array, we must reshape, because transpose does not seem to perform
this task.
"""
import numpy as np 

arr = np.array([1, 2, 3])

arr2 = arr + arr	# Summing two arrays.
arr2 += 2	# Adding two
arr **= 2	# Power of two.

print(arr2)
print(arr)

arr2 = np.array([[1, 2, 3], [4, 5, 6]])
print(arr2.transpose())
# Equivalently
print(arr2.T)	
