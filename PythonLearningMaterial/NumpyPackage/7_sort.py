"""
The simple np.sort method is used for sorting arrays. It's also possible to sort with respect to structured
data, as shown below. We can also sort with respect to two parameters.
Me: I couldn't figure out how to make sort descending

We can also use the partition to sort with respect to a particular element. 
"""

import numpy as np

arr = np.array([4, 2, 3, 1, 5])
print(np.sort(arr, axis=-1, kind='quicksort'))

arr = np.array([3, 4, 1, 5, 6, 7, 0])
print(np.partition(arr, 2))	# Only the third element is sorted.

# Sorting structured date
## Defining aliases for types.
dtypes = [('name', 'S10'), ('graduation', int), ('average', int)]
values = [("Masoud", 2015, 16), ("Masoud", 2012, 15), ("Navid", 2022, 19), ("Babak", 2014, 19)]
structured_arr = np.array(values, dtypes)

sorted_struc_arr = np.sort(structured_arr, order='name')
print(sorted_struc_arr)

sort_by_two_params = np.sort(sorted_struc_arr, order=['name', 'graduation'])