"""
When looping through lists, we can use the enumerate function to get the (index, value) pair.
"""

ls = ["a", "b", "c"]

for i, v in enumerate(ls):
	print(i, v)