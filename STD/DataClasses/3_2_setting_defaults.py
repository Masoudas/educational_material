"""
If the default value of a field is specified by a call to field(), then the class attribute for this field will be 
replaced by the specified default value. If no default is provided, then the class attribute will be deleted. The 
intent is that after the dataclass() decorator runs, the class attributes will all contain the default values for 
the fields, just as if the default value itself were specified. For example, after:

@dataclass
class C:
    x: int
    y: int = field(repr=False)
    z: int = field(repr=False, default=10)
    t: int = 20

The class attribute C.z will be 10, the class attribute C.t will be 20, and the class attributes C.x and C.y will 
not be set.
"""
from dataclasses import dataclass, field

@dataclass
class C:
    x: int
    y: int = field(repr=False)
    z: int = field(repr=False, default=10)
    t: int = 20

c = C(1, 2)	# Requires two parameters for initialization. That is, x and y.
print(c, f"and z={c.z}, y={c.y}")