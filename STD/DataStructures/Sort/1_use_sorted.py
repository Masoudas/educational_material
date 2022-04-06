"""
We can sort complex data structures using the sorted function, which sorts in ascending order.

Note that we can also sort tuples. But the result will always be a list.

We may also supply a lambda for custom sorts. This lambda needs only to return a key, and it's not a comparison function.
(which is better than compare method believe me!)
"""

ls = ["my", "why", "at"]
sorted(ls)

tpl = (1, 4, 2, 3)
print(sorted(tpl))	# Returns a tuple.

ls_dicts = [{"name": 20}, {"name": 15}, {"name": 30}]
print(sorted(ls_dicts, key=lambda d1 : d1["name"]))	# Just returns the key.