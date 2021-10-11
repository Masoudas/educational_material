"""
PODs can be created as suggested by the standard in the following manner.

Note that instance method objects have attributes too: m.__self__ is the instance object with the method m(), and 
m.__func__ is the function object corresponding to the method.
"""

class POD:
	pass 

pod = POD()
pod.name = "Masoud"
pod.last_name = "Sharbaf"


"""
Me: However, I prefer the following way!
"""
class POD:
	def __init__(self):
		self.name = ""
		self.last_name = ""

pod = POD()
