"""
From section 9 of tutorials
As is mentioned by the standard, namespaces are dictionaries (for the moment) containing the names in the current
space.

As it also says "Namespaces are created at different moments and have different lifetimes. The namespace containing 
the built-in names is created when the Python interpreter starts up, and is never deleted. The global namespace for 
a module is created when the module definition is read in; normally, module namespaces also last until the 
interpreter quits. The statements executed by the top-level invocation of the interpreter, either read from a script 
file or interactively, are considered part of a module called __main__, so they have their own global namespace. 
(The built-in names actually also live in a module; this is called builtins.)

The local namespace for a function is created when the function is called, and deleted when the function returns or 
raises an exception that is not handled within the function. Of course, recursive invocations each have their own 
local namespace.

A scope is a textual region of a Python program where a namespace is directly accessible. “Directly accessible” here 
means that an unqualified reference to a name attempts to find the name in the namespace."

The discussion went crazy from here, so I skipped it!
"""

if True:
	g = 1

for x in [1]:
	h = 1

x = 0
while (x < 1):
	i = 1
	x += 1

with open("Classes/1_on_name_spaces.py"):	# Notice, however, that the opened file will be closed once the with
											# loop terminates.
	j = 1

print(g, h, i, j)	# Well. In Python for loops and ifs, withs and whiles don't create a new scope.