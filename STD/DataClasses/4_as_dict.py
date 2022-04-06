"""
	-	dataclasses.asdict(instance, *, dict_factory=dict)
Converts the dataclass instance to a dict (by using the factory function dict_factory). Each dataclass is converted
to a dict of its fields, as name: value pairs. dataclasses, dicts, lists, and tuples are recursed into. 

There's also a corresponding as tuple class.

For example:
"""

from dataclasses import asdict, dataclass

@dataclass
class Point:
     x: int
     y: int

@dataclass
class C:
     mylist: list[Point]

p = Point(10, 20)
assert asdict(p) == {'x': 10, 'y': 20}

c = C([Point(0, 0), Point(10, 4)])
assert asdict(c) == {'mylist': [{'x': 0, 'y': 0}, {'x': 10, 'y': 4}]}