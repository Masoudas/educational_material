"""
The operators is and is not check whether two objects are really the same. Note that all comparison operators have
the same priority, which is less than numerical operators. (Me: As a side note, the content of objects is compared
using ==. This is particularly true for strings)

Me: Recall that two objects occupying the same memory and two objects having the same data is two different things.

Comparison of primitive types is done using the '==' operator.


"""
ls = []
ls1 = ls

if ls is ls1 and ls == ls1 and 2 != 1 + 3:	# Note that first 1 + 3 is calculated, and then comparison is done.
	print("All comparisons are valid") 



