"""
Returns True if the two objects are of the same geometric type, and the coordinates of the two objects match precisely.
"""
from shapely.geometry import LineString

l1 = LineString([[0,0], [1, 1]])
l2 = LineString([[0,0], [1, 1], [1, 1]])
l3 = LineString([[0,0], [1, 1]])

print("l1 equals l3:", l1 == l3)
print("l1 does not equal l2:", l1 != l2)

