"""
Returns True if coordinates are in counter-clockwise order (bounding a region with positive signed area). This method applies to LinearRing objects only.
"""
from shapely.geometry import LineString

cw = LineString([[0,0], [1, 1]])
ccw = LineString([[1, 1], [0,0]])
random = LineString([[0,0], [1, 0], [0, 1], [1, 1]])

print("Clockw-ise", cw.)