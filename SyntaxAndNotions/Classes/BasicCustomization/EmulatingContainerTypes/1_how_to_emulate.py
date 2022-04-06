"""
The following methods can be defined to implement container objects. Containers usually are sequences 
(such as lists or tuples) or mappings (like dictionaries), but can represent other containers as well. 
The first set of methods is used either to emulate a sequence or to emulate a mapping; the difference 
is that for a sequence, the allowable keys should be the integers k for which 0 <= k < N where N is the 
length of the sequence, or slice objects, which define a range of items. It is also recommended that 
mappings provide the methods keys(), values(), items(), get(), clear(), setdefault(), pop(), popitem(), 
copy(), and update() behaving similar to those for Python’s standard dictionary objects. The 
collections.abc module provides a MutableMapping abstract base class to help create those methods from 
a base set of __getitem__(), __setitem__(), __delitem__(), and keys(). Mutable sequences should provide 
methods append(), count(), index(), extend(), insert(), pop(), remove(), reverse() and sort(), like 
Python standard list objects. Finally, sequence types should implement addition (meaning concatenation) 
and multiplication (meaning repetition) by defining the methods __add__(), __radd__(), __iadd__(), 
__mul__(), __rmul__() and __imul__() described below; they should not define other numerical operators. 
It is recommended that both mappings and sequences implement the __contains__() method to allow efficient 
use of the in operator; for mappings, in should search the mapping’s keys; for sequences, it should search 
through the values. It is further recommended that both mappings and sequences implement the __iter__() 
method to allow efficient iteration through the container; for mappings, __iter__() should iterate through 
the object’s keys; for sequences, it should iterate through the values.
"""