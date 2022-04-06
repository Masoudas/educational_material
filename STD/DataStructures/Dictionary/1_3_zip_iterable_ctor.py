"""
Assume that we have two lists. what zip does is to creater an iterable from both of these lists together. As
such, if we zip two vectors together and pass the iterable to a dictionary, we can create a dictionary from it.
"""
keys = ["k1", "k2", "k3", "k4"]
vals = [1, 2, 3, 4]

d = dict(zip(keys, vals))

print(d)