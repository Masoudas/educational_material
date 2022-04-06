"""
	-	dataclasses.make_dataclass(cls_name, fields, *, bases=(), namespace=None, init=True, repr=True, eq=True, 
	order=False, unsafe_hash=False, frozen=False, match_args=True, kw_only=False, slots=False)

Me: Essentially, this is a factory method for creating a dataclass, without actually defining it explicitly!

Creates a new dataclass with name cls_name, fields as defined in fields, base classes as given in bases, and 
initialized with a namespace as given in namespace. fields is an iterable whose elements are each either name, 
(name, type), or (name, type, Field). If just name is supplied, typing.Any is used for type. The values of init, 
repr, eq, order, unsafe_hash, frozen, match_args, kw_only, and slots have the same meaning as they do in 
dataclass().

This function is not strictly required, because any Python mechanism for creating a new class with __annotations__ 
can then apply the dataclass() function to convert that class to a dataclass. This function is provided as a 
convenience. 
"""