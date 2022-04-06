"""
It's possible to add new axises to an array. As such, the arrangement of the array changes as well. Below, we
add a new axis to create a new dimension.

In the next example, we combine adding new-axis and broadcasting to create a matrix from a row and column vector.
"""

import numpy as np

row_arr = np.array([1, 2, 3])
col_arr = row_arr[:, np.newaxis]

print(row_arr, " versus ", col_arr)

# Creating a matrix
matrix = col_arr + row_arr	# Notice that the single column is added to every column of the single row.
print(matrix)