"""
Note that if a dictionary does not have a key, then accessing that key using the bracket operator results in an exception
being raised.

To avoid this scenario, we may use the get function. The function accepts a default value as argument and if the key
does not exist, then that default value is returned.

The method setDefault is like get. The difference, however, is that setDefault actually defines the key value pair in
the function, apart from just returning it.

"""
d = {"a": 1, "b": 2}

try:
	d["c"]
except KeyError:
	print("Exception was raised.")

print("For a non-existent key, the given default value of -1 is returned with the get method: ", d.get("c", -1))
print("If no value is supplied, then None will be retunred: ", d.get("c", -1))

# Now, aside from the fact for this non-existent key, the value -1 is returned, the key value pair (c,-1) is also
# defined in the dictionary.
d.setdefault("c", -1)

