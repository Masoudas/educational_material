"""
	-	object.__getitem__(self, key)
Called to implement evaluation of self[key]. For sequence types, the accepted keys should be integers and 
slice objects. Note that the special interpretation of negative indexes (if the class wishes to emulate a 
sequence type) is up to the __getitem__() method. If key is of an inappropriate type, TypeError may be 
raised; if of a value outside the set of indexes for the sequence (after any special interpretation of 
negative values), IndexError should be raised. For mapping types, if key is missing (not in the 
container), KeyError should be raised.

Note for loops expect that an IndexError will be raised for illegal indexes to allow proper detection of 
the end of the sequence.
	
	-	object.__setitem__(self, key, value)
Called to implement assignment to self[key]. Same note as for __getitem__(). This should only be 
implemented for mappings if the objects support changes to the values for keys, or if new keys can be 
added, or for sequences if elements can be replaced. The same exceptions should be raised for improper 
key values as for the __getitem__() method.

	-	object.__delitem__(self, key)
Called to implement deletion of self[key]. Same note as for __getitem__(). This should only be implemented 
for mappings if the objects support removal of keys, or for sequences if elements can be removed from the 
sequence. The same exceptions should be raised for improper key values as for the __getitem__() method.

	-	object.__missing__(self, key)
Called by dict.__getitem__() to implement self[key] for dict subclasses when key is not in the dictionary.
"""