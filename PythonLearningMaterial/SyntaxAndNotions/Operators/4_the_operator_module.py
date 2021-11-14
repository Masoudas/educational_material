"""
The operator module contains all the python operators. This includes the not_ operator, and also and_ (bitwise
and) and or_ (bitwise or) etc.

An interesting use is with functions like filter, map, etc.
"""
import operator

print(operator.not_(42))
print(operator.and_(42, 1))	# will be zero
print(42 & 1)	# will be zero

ls = ["", "a"]
print(list(filter(operator.not_, ls)))	# The empty items!

