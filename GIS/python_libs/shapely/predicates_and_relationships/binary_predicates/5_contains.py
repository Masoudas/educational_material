"""
Returns True if no points of other lie in the exterior of the object and at least one point of the interior of other lies in the interior of object (Me: By saying interior, we exclude the bounadry).

This predicate applies to all types, and is inverse to within(). The expression a.contains(b) == b.within(a) always evaluates to True.

Note: A line's endpoints are part of its boundary and are therefore not contained.
"""
from shapely.geometry import LineString, Point

coords = [(0, 0), (1, 1)]

LineString(coords).contains(Point(0.5, 0.5)) # True
Point(0.5, 0.5).within(LineString(coords)) # True

# Line end points are part of its boundary, hence this is False.
LineString(coords).contains(Point(1.0, 1.0))
print(LineString(coords).contains(Point(0.0, 0.0)))
