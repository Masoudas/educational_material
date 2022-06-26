"""
Returns True if the objects have at least one point in common and their interiors do not intersect with any part of the other.

Me: Exactly what we expect for touch. Meaning only boundaries overlap (in at least one point)!
"""
from shapely.geometry import LineString, Point

a = LineString([(0, 0), (1, 1)])
b = LineString([(1, 1), (2, 2)])
a.touches(b)