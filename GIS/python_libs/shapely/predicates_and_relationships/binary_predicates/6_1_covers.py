"""
Returns True if every point of other is a point on the interior or boundary of object. This is similar to object.contains(other) except that this does not require any interior points of other to lie in the interior of object.
"""
from shapely.geometry import LineString, Point

coords = [(0, 0), (1, 1)]

# Line end points are part of its boundary, hence this is False.
LineString(coords).contains(Point(1.0, 1.0))

# But this is True
LineString(coords).covers(Point(1.0, 1.0))
