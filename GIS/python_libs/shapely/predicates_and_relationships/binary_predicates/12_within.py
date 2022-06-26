"""
Returns True if the object’s boundary and interior intersect only with the interior of the other (not its boundary or exterior).

ME: Exactly what we expect for within. It must not touch the boundary of the other object.

This applies to all types and is the inverse of contains().

Used in a sorted() key, within() makes it easy to spatially sort objects. Let’s say we have 4 stereotypic features: a point that is contained by a polygon which is itself contained by another polygon, and a free spirited point contained by none. Then, we’d prefer to have ordered as [d, c, c, b, a] in reverse containment order. As explained in the Python Sorting HowTo, we can define a key function that operates on each list element and returns a value for comparison. Our key function will be a wrapper class that implements __lt__() using Shapely’s binary within() predicate.

class Within:
    def __init__(self, o):
        self.o = o
    def __lt__(self, other):
        return self.o.within(other.o)
"""
from shapely.geometry import LineString, Point, Polygon

a = Point(2, 2)
b = Polygon([[1, 1], [1, 3], [3, 3], [3, 1]])
c = Polygon([[0, 0], [0, 4], [4, 4], [4, 0]])
d = Point(-1, -1)

features = [c, a, d, b, c]

class Within:
    def __init__(self, o):
        self.o = o
    def __lt__(self, other):
        return self.o.within(other.o)

[d, c, c, b, a] == sorted(features, key=Within, reverse=True) 