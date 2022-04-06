"""
	-	Mappings
These represent finite sets of objects indexed by arbitrary index sets. The subscript notation a[k] selects the item 
indexed by k from the mapping a; this can be used in expressions and as the target of assignments or del statements. The built-in function len() returns the number of items in a mapping.

There is currently a single intrinsic mapping type:

	-	Dictionaries
These represent finite sets of objects indexed by nearly arbitrary values. The only types of values not acceptable 
as keys are values containing lists or dictionaries or other mutable types that are compared by value rather than 
by object identity, the reason being that the efficient implementation of dictionaries requires a key’s hash value 
to remain constant. Numeric types used for keys obey the normal rules for numeric comparison: if two numbers 
compare equal (e.g., 1 and 1.0) then they can be used interchangeably to index the same dictionary entry (Me: Ok!).

Dictionaries preserve insertion order, meaning that keys will be produced in the same order they were added 
sequentially over the dictionary. Replacing an existing key does not change the order, however removing a key and 
re-inserting it will add it to the end instead of keeping its old place.

Dictionaries are mutable; they can be created by the {...} notation (see section Dictionary displays).

The extension modules dbm.ndbm and dbm.gnu provide additional examples of mapping types, as does the collections 
module.

Changed in version 3.7: Dictionaries did not preserve insertion order in versions of Python before 3.6. In 
CPython 3.6, insertion order was preserved, but it was considered an implementation detail at that time rather 
than a language guarantee.
"""