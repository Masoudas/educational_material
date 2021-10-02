"""
We can split numpy arrays. Note that split returns views, and not copies:
	-	np.hsplit: Split array along horizontal axis.
	-	np.vsplit: Split array along vertical axis.
	-	np.array_split: Split array along specified axis.

We can also stack (merge) arrays:
	-	np.vstack: To stack arrays along vertical axis.
	-	np.hstack: To stack arrays along horizontal axis.
	-	np.column_stack: To stack 1-D arrays as columns into 2-D arrays.
	-	np.concatenate: To stack arrays along specified axis (axis is passed as argument).

https://www.geeksforgeeks.org/numpy-python-set-2-advanced/
"""
import numpy as np

arr1 = np.array([1, 2, 3, 4])
arr2 = np.array([5, 6, 7, 8])

print(np.hstack([arr1, arr2]))	# Stack the vectors consecutively to form a horizontal array
print(np.vstack([arr1, arr2]))	# Stack vectors on top of one another to form a 2d array.

# Equivalently
print(np.concatenate([arr1, arr2], axis=0))
# print(np.concatenate([arr1, arr2], axis=1))	Impossible to create a new dimension with this method.

arr3 = np.split(arr1, 2, axis=0)	# Split from index 2. Hence, the second view contains index 2.
print(arr3[0], arr3[1], arr1)
