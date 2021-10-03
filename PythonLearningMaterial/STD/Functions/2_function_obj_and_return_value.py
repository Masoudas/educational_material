"""
A function definition associates the function name with the function object in the current symbol table. The 
interpreter recognizes the object pointed to by that name as a user-defined function. Other names can also point 
to that same function object and can also be used to access the function. As such, we can treat functions as
objects, and hence for example, compare their names, etc.

Note that all functions return values. However, functions with no return value return None.
"""

def fib():
	return

print(fib)

f = fib	# Keeps the name and properties of the original function

if f.__name__ == 'fib' and f() is None:
	print("The function name is", f.__name__, "and the return value is none")