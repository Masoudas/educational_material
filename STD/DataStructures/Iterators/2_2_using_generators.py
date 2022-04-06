"""
Using generators is a powerful way of creating iterators in Python. 

The point is that we use the yield expression, which would yield the result in every iteration of the loop, as shown
below. Each time next() is called on it, the generator resumes where it left off (it remembers all the data values 
and which statement was last executed).

Note that as opposed to class iterators, generators have to be implemented as standalone methods. The next method
can't return this iterator.
"""

class c:
	def __init__(self):
		self.ls = [1, 2, 3]

def reverse(c : c):
	for i in range(len(c.ls) - 1, -1, -1):
		yield c.ls[i]

ls = c()

for val in reverse(ls):
	print(val)

