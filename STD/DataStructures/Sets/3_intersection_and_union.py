"""
These are two very useful methods for getting common values or unions.
"""

s1 = {1, 2, 3}
s2 = {2, 3, 4}
s3 = {3, 4, 5}

print(s1.intersection(s2, s3))
print(s1.union(s1, s2, s3))

print(s1.difference(s2, s3))