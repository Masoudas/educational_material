"""
Question: When we search for a class in a collection of classes, does it use the __eq__ method or the is method?
Meaning, does it compare the instance, or data (or both?)

Well, apparently it uses the __eq__ method. So, if the __eq__ method is not overriden, we know that the default
__eq__ method returns true if the id of the two objects is equal. So, in that case, we compare instances (or use
is.)

Essentially, we use the __eq__ method, and for tuples, we use that recursively.
"""
class A:
	def __eq__(self, o):
		print("Inside equal method")
		return True 


my_list = [A(), A()]
print(A() in my_list)	# Returns True

class B:
	pass 

my_list1 = [B(), B(), B()]
print(B() in my_list1)	# Returns False