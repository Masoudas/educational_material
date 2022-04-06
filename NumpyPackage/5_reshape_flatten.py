"""
We can reshape or flatten an array as required, both of which return new arrays to us.
"""

import numpy as np

two_dim = np.array([1, 2, 3, 4, 5, 6]).reshape([2, 3])
print(two_dim)

flat = two_dim.flatten()
print(flat)