"""
To use global variables, use the global keyword. We can't change the variable otherwise for setting it, but to 
read it, we use LEGB. 

Note that the variable name does not have to be defined
"""
x = 'a'

def set_global():
	global x 
	global y
	x = 20

	y = 10

print(y)	# Defined here to.
