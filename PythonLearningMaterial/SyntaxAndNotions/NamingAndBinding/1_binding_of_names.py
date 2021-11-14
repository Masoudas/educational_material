"""
The following constructs bind names: 
	-	formal parameters to functions, 
	-	import statements, 
	-	class and function definitions (these bind the class or function name in the defining block), and 
	-	targets that are identifiers if occurring in an assignment, for loop header, or after as in a with 
		statement or except clause. 

The import statement of the form from ... import * binds all names defined in the imported module, except those 
beginning with an underscore. This form may only be used at the module level.

Me: What's missing from here is a for loop, if loop, etc
"""

def f():
	x = 10

f()
print(x)	# Error! Bound to the function, not the global scope.