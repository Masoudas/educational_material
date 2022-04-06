"""
We must remember that to check for None and bool, we should preferably use is, because we're comparing instances.
"""
x = None
if x is None:
	print()

y = True 
if y is True and y is not False:
	print()
