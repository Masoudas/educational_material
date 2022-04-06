"""
Called when dir() is called on the object. A sequence must be returned. dir() converts the returned sequence to a 
list and sorts it.

Me: dir prints the namespace dictionary of the class.
"""
class c:
	pass 

print(c().__dir__())