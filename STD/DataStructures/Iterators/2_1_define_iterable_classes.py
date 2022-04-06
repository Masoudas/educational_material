"""
As such, it's easy to define classes that implement the iterable pattern. The class needs to implement the __next__
method to that end, and we can define the iterator class as the class itself in that scheme. Hence, the __iter__
method would return self as the iterator.
"""

class iterable:
	def __init__(self):
		self.ls = [1, 2, 3]
		self.__itr = self.ls.__iter__()

	def __iter__(self):
		"""Return the iterator associated with this class
		"""
		return self

	def __next__(self):
		"""The next method of the iterator"""
		return self.__itr.__next__()

itr = iterable()

for elem in itr:
	print(elem)