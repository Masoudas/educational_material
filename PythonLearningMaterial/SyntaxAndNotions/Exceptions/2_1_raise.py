"""
We can raise exceptions using the raise statement. Notice that we may or may nor construct an exception object.

Note that docstrings are the only way to annotate exceptions
"""

def f():
	"""[summary]

	Raises:
		ZeroDivisionError: This is the documentation.
	"""
	raise ZeroDivisionError
