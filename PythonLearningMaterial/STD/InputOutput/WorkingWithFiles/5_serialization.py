"""
The json package which is native to Python allows serialization of internal python data structures, as the following
example demonstrates.

The dumps method creates a serializable object, that is a simple json string. The dump method allows to write this
string directly into a json. The load method does the reverse.

Note: Technically, we must dump only one object, and not as I do below, dump two different objects in one file!

To dump classe, we need a little bit of extra effort. Another method is pickling.
"""
import json 

ls = [1, "my str", 2]
dictionary = {"key1" : "val1", "key2" : "val2"}

with open("objects.json", "w") as f:
	json.dump(ls,f)
	json.dump(dictionary, f)


