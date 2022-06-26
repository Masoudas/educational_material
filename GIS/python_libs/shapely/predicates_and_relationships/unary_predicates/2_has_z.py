"""
Returns True if the feature has not only x and y, but also z coordinates for 3D 
(or so-called, 2.5D) geometries.
"""
from shapely.geometry import LineString

l1 = LineString([[0,0,0], [1,0,0]])
l2 = LineString([[0,0], [1, 0]])

print("Is 3D:", l1.has_z)
print("Is not 3D:", not l2.has_z)
