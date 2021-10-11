"""
Essentially, the lambda expression requires the name of the input argument, and usually the lambda is only one
expression long. This is shown in the example below. 

Me: As such, lambda expressions don't accept a return statement.
"""

lambda x : x * 10	# A lambda expression
expr = lambda x : x * 10

print(expr(10))