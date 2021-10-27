"""
	-	@dataclasses.dataclass(*, init=True, repr=True, eq=True, order=False, unsafe_hash=False, frozen=False, 
		match_args=True, kw_only=False, slots=False)
	Me: These are pretty much the internal methods of a class, including:

The dataclass() decorator examines the class to find fields. A field is defined as a class variable that has a 
type annotation. With two exceptions described below, nothing in dataclass() examines the type specified in the 
variable annotation.

The order of the fields in all of the generated methods is the order in which they appear in the class definition.

If dataclass() is used just as a simple decorator with no parameters, it acts as if it has the default values 
documented in this signature. That is, these three uses of dataclass() are equivalent:

@dataclass
class C:
    ...

@dataclass()
class C:
    ...

@dataclass(init=True, repr=True, eq=True, order=False, unsafe_hash=False, frozen=False, match_args=True, 
	kw_only=False, slots=False)
class C:

The parameters to dataclass() are:

	-	init: If true (the default), a __init__() method will be generated. If the class already defines __init__(), 
	this parameter is ignored.

	-	repr: If true (the default), a __repr__() method will be generated. The generated repr string will have the 
	class name and the name and repr of each field, in the order they are defined in the class. Fields that are 
	marked as being excluded from the repr are not included. For example: 

	InventoryItem(name='widget', unit_price=3.0, quantity_on_hand=10).

	If the class already defines __repr__(), this parameter is ignored.

	-	eq: If true (the default), an __eq__() method will be generated. This method compares the class as if it 
	were a tuple of its fields, in order. Both instances in the comparison must be of the identical type.
	If the class already defines __eq__(), this parameter is ignored.

	-	order: If true (the default is False), __lt__(), __le__(), __gt__(), and __ge__() methods will be generated. 
	These compare the class as if it were a tuple of its fields, in order. Both instances in the comparison must be 
	of the identical type. If order is true and eq is false, a ValueError is raised.

	If the class already defines any of __lt__(), __le__(), __gt__(), or __ge__(), then TypeError is raised.

	-	unsafe_hash: If False (the default), a __hash__() method is generated according to how eq and frozen are 
	set.

	-	__hash__() is used by built-in hash(), and when objects are added to hashed collections such as 
	dictionaries and sets. Having a __hash__() implies that instances of the class are immutable. Mutability is a 
	complicated property that depends on the programmer’s intent, the existence and behavior of __eq__(), and the 
	values of the eq and frozen flags in the dataclass() decorator.

	By default, dataclass() will not implicitly add a __hash__() method unless it is safe to do so. Neither will it 
	add or change an existing explicitly defined __hash__() method. Setting the class attribute __hash__ = None has 
	a specific meaning to Python, as described in the __hash__() documentation.

	If __hash__() is not explicitly defined, or if it is set to None, then dataclass() may add an implicit 
	__hash__() method. Although not recommended, you can force dataclass() to create a __hash__() method with 
	unsafe_hash=True. This might be the case if your class is logically immutable but can nonetheless be mutated. 
	This is a specialized use case and should be considered carefully.

	Here are the rules governing implicit creation of a __hash__() method. Note that you cannot both have an 
	explicit __hash__() method in your dataclass and set unsafe_hash=True; this will result in a TypeError.

	If eq and frozen are both true, by default dataclass() will generate a __hash__() method for you. If eq is true 
	and frozen is false, __hash__() will be set to None, marking it unhashable (which it is, since it is mutable). 
	If eq is false, __hash__() will be left untouched meaning the __hash__() method of the superclass will be used 
	(if the superclass is object, this means it will fall back to id-based hashing).

	-	frozen: If true (the default is False), assigning to fields will generate an exception. This emulates 
	read-only frozen instances. If __setattr__() or __delattr__() is defined in the class, then TypeError is raised. 
	

	-	match_args: If true (the default is True), the __match_args__ tuple will be created from the list of 
	parameters to the generated __init__() method (even if __init__() is not generated, see above). If false, or 
	if __match_args__ is already defined in the class, then __match_args__ will not be generated.

	New in version 3.10.

	-	kw_only: If true (the default value is False), then all fields will be marked as keyword-only. If a field 
	is marked as keyword-only, then the only affect is that the __init__() parameter generated from a keyword-only 
	field must be specified with a keyword when __init__() is called. There is no effect on any other aspect of 
	dataclasses. 

	-	slots: If true (the default is False), __slots__ attribute will be generated and new class will be returned 
	instead of the original one. If __slots__ is already defined in the class, then TypeError is raised.
"""