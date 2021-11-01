"""
The membership test operators (in and not in) are normally implemented as an iteration through a container. 
However, container objects can supply the following special method with a more efficient implementation, which 
also does not require the object be iterable.

	-	object.__contains__(self, item)
Called to implement membership test operators. Should return true if item is in self, false otherwise. For 
mapping objects, this should consider the keys of the mapping rather than the values or the key-item pairs.

For objects that don’t define __contains__(), the membership test first tries iteration via __iter__(), then 
the old sequence iteration protocol via __getitem__(), see this section in the language reference.
"""