"""
The operators is and is not check whether two objects are really the same. Note that all comparison operators have
the same priority, which is less than numerical operators.

Me: Recall that two objects occupying the same memory and two objects having the same data is two different things.

Comparison of primitive types is done using the '==' operator.
"""
ls = []
ls1 = ls

if ls is ls1:
	print("Both objects are the same place in memory") 





