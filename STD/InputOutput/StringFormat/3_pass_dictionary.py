"""
It's possible to pass a dictionary directly to a formatted string as well. The place holders should be filled as
{0[key]:}, which would print the value of the given key in string format, as the following example demonstrates.

Or, we can expand the dictionray and then use the keys.
"""

table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 8637678}
print('Jack: {0[Jack]:d}; Sjoerd: {0[Sjoerd]:d}; Dcab: {0[Dcab]:d}'.format(table))

print('Jack: {Jack}; Sjoerd: {Sjoerd}; Dcab: {Dcab}'.format(**table))