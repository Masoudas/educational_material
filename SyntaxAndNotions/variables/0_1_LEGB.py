"""
Local, enclosing, global and built-in is the search tree for a variable. 

Local means inside a function.

The built-ins can be accessed and printed using the builtin.

Enclosing scope has to do with nested functions. Nested ones have access to the ones outside. It's pretty much
like accessing a global variable inside a function. meaning we can read, but not write. To change the variable
of outer function, we must use the 'nonlocal' keyword.

Finally, note that conditionls (ifs, whiles, etc) don't define new scopes, and variables defined in them are
like variables defined anywhere else.
"""

x = 'global variable'
def test():
	y = 'local variable'
	print(y)	# Uses LEGB
	print(x)	# Uses LEGB, finds x in global scope.

	x = 'local x'		# Creates a local x variable. Outside it's still unchanged.
	print(x) 

	# The set the global variable. (I think)
	globals()['x'] = 10

# print(y) It's not in LEGB, because it is not in local, enclosing, or global

def outer():
	x = 10
	def inner():
		nonlocal x 
		x = 20
		print(x) # Has x.
