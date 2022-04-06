"""
There's a reverse situation, where we need to unpack an iterable to for example pass it to a function. We can do
so, using the '*' operator for lists and '**' for dictionaries.
"""
def f(kind, *args, **kwargs):
	for arg in args:
		print(arg)

	for key in kwargs:
		print(f"({key}, {kwargs[key]})")

list = ["val1", "val2"]
pairs = {"key1":"val1", "key2":"val2", "key3":"val3"}

f(1, *list, **pairs)