"""
The data type for a dictionary is 'dict'.

Keys in dictionaries have to be unique and immutable. The latter is important, because it's considered unhashable
in Python. Hence, for example a list can't be the key to a dictionary. because its hash changes everytime, and
Python throws an error for such mutable data. It can, of course, be the value. Tuples, however, can be used, as 
they're immutable.

A class that has only immutable data can also be used as keys.

Note that the value of an exisiting key is replaced, and not appended! Accessig non-existing keys throws a KeyError
exception.

PEP note: We put a space after the column of the list.

Does a pair of braces create a dictionary or a set? It creates a dictionary!
"""

# dic = {[1] : "Val"} # Error Unhashable type

class immutable:
	def __init__(self, str=""):
		self.str = str
dic = {immutable() : []}	# Ok!

dic = {"Key1": 1}
dic["Key1"] = 2	# Replaces one.
print(dic)

if type({}) is dict:	# Notice the correct type comparison
	print("Empty braces are a dictionary")

try:
	 dic[1]
except KeyError:
	print("Key not found")
