"""
Numpy broadcasting rules allow looping to occur in C rather than in python.

The Broadcasting Rule: In order to broadcast, the size of the trailing axes for both arrays in an operation must 
either be the same size or one of them must be one.

Example: 4*3 and 1*3. Or 3*1 and 3. But 2*2 and 3 is not acceptable.
"""
import numpy as np

a = np.array([1.0, 2.0, 3.0])

# Example 1
b = 2.0
print(a * b)

# Example 2
c = [2.0, 2.0, 2.0]
print(a * c)


