"""
	-	dataclasses.KW_ONLY
A sentinel value used as a type annotation. Any fields after a pseudo-field with the type of KW_ONLY are marked as 
keyword-only fields. Note that a pseudo-field of type KW_ONLY is otherwise completely ignored. This includes the 
name of such a field. By convention, a name of _ is used for a KW_ONLY field. Keyword-only fields signify 
__init__() parameters that must be specified as keywords when the class is instantiated.

In this example, the fields y and z will be marked as keyword-only fields:

@dataclass
class Point:
	x: float
	_: KW_ONLY	# So a field named _ is keyword only.
	y: float
	z: float

p = Point(0, y=1.5, z=2.0)

In a single dataclass, it is an error to specify more than one field whose type is KW_ONLY.
"""