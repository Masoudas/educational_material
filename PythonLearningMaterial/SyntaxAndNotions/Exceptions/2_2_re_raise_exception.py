"""
If we don't intend to handle an exception, we can use simply raise the same exception by just writing the raise
keyword. 

An equivalent catching as argument is also fine.
"""
try:
	raise ValueError
except ValueError:
	raise

try:
	raise ValueError
except ValueError as r:
	raise r	# T

