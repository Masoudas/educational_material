"""
The linear algebra library inside the numpy library allows for algebraic operations on arrays.
"""

import numpy as np
  
A = np.array([[6, 1, 1],
              [4, -2, 5],
              [2, 8, 7]])
  
print("Rank of A:", np.linalg.matrix_rank(A)) 
print("\nTrace of A:", np.trace(A))
print("\nDeterminant of A:", np.linalg.det(A))
print("\nInverse of A:\n", np.linalg.inv(A))
print("\nMatrix A raised to power 3:\n", np.linalg.matrix_power(A, 3))
  
# coefficients
a = np.array([[1, 2], [3, 4]])
# constants
b = np.array([8, 18])
  
print("Solution of linear equations:", np.linalg.solve(a, b))
