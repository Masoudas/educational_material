"""
It's also possible to append two dictionaries together by unpacking them in a third dictionary, as the following example
demonstrates.
"""
d1 = {1:1, 2:2, 3:3}
d2 = {4:4, 5:5, 6:6}

d3 = {**d1, **d2}
print(d3)