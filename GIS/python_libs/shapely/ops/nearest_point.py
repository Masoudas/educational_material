"""
Returns a tuple of the nearest points in the input geometries. The points are returned in the same order as the input geometries.
"""
from shapely.ops import nearest_points
from shapely.geometry import LineString

l1 = LineString([[0, 0], [0, 1]])
l2 = LineString([[0.1, 0.1], [1, 0.1]])

nearest = nearest_points(l1, l2)
print(nearest[0], nearest[1])
