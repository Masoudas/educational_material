"""
fields may optionally specify a default value, using normal Python syntax:

TypeError will be raised if a field without a default value follows a field with a default value. This is true 
whether this occurs in a single class, or as a result of class inheritance.

There's a decorator associated with a field as follows:
	dataclasses.field(*, default=MISSING, default_factory=MISSING, init=True, repr=True, hash=None, compare=True, 
	metadata=None, kw_only=MISSING)

	For common and simple use cases, no other functionality is required. There are, however, some dataclass features 
	that require additional per-field information. To satisfy this need for additional information, you can replace 
	the default field value with a call to the provided field() function. For example:

@dataclass
class C:
    mylist: list[int] = field(default_factory=list)

c = C()
c.mylist += [1, 2, 3]

	As shown above, the MISSING value is a sentinel object used to detect if some parameters are provided by the 
	user. This sentinel is used because None is a valid value for some parameters with a distinct meaning. No code 
	should directly use the MISSING value. (Me: Talking about the kw_only key in the field decorator.)

The parameters to field() are:
	-	default: If provided, this will be the default value for this field. This is needed because the field() 
	call itself replaces the normal position of the default value.

	-	default_factory: If provided, it must be a zero-argument callable that will be called when a default value 
	is needed for this field. Among other purposes, this can be used to specify fields with mutable default values, 
	as discussed below. It is an error to specify both default and default_factory.

	-	init: If true (the default), this field is included as a parameter to the generated __init__() method.

	-	repr: If true (the default), this field is included in the string returned by the generated __repr__() 
	method.

	-	hash: This can be a bool or None. If true, this field is included in the generated __hash__() method. If 
	None (the default), use the value of compare: this would normally be the expected behavior. A field should be 
	considered in the hash if it’s used for comparisons. Setting this value to anything other than None is 
	discouraged.

	One possible reason to set hash=False but compare=True would be if a field is expensive to compute a hash value 
	for, that field is needed for equality testing, and there are other fields that contribute to the type’s hash 
	value. Even if a field is excluded from the hash, it will still be used for comparisons.

	-	compare: If true (the default), this field is included in the generated equality and comparison methods 
	(__eq__(), __gt__(), et al.).

	-	metadata: This can be a mapping or None. None is treated as an empty dict. This value is wrapped in 
	MappingProxyType() to make it read-only, and exposed on the Field object. It is not used at all by Data 
	Classes, and is provided as a third-party extension mechanism. Multiple third-parties can each have their 
	own key, to use as a namespace in the metadata.

	-	kw_only: If true, this field will be marked as keyword-only. This is used when the generated __init__() 
	method's parameters are computed.

"""
from dataclasses import dataclass
@dataclass
class C:
    a: int       # 'a' has no default value
    b: int = 0   # assign a default value for 'b'