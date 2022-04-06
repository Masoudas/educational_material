"""
Here are several examples of dictionary construction:
"""

# From a list of tuples
dict([('sape', 4139), ('guido', 4127), ('jack', 4098)])

# From list comprehension.
{x: x**2 for x in (2, 4, 6)} 

# With key value pairs:
dict(sape=4139, guido=4127, jack=4098)