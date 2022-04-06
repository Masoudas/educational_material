"""
We can pass a list and set of key value pairs to a function, using the *args, and **kwargs notation, as shown
below.
"""

def f(kind, *args, **kwargs):
	for arg in args:
		print(arg)

	for key in kwargs:
		print(f"({key}, {kwargs[key]})")
	

f(42, "val1", "val2", key1="val1", key2="val2", key3="val3")

# Another calling method
f(42, *["val1", "val2"], **{"key1":"val1", "key2":"val2", "key3":"val3"})