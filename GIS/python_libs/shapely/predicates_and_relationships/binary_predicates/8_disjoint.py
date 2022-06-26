"""
Returns True if the boundary and interior of the object do not intersect at all with those of the other.

This predicate applies to all types and is the inverse of intersects().
"""
from shapely.geometry import LineString, Point

Point(0, 0).disjoint(Point(1, 1)) # True