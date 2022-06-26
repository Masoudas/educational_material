"""
Returns True if the object is approximately equal to the other at all points to specified decimal place precision.

Me: Does it look at the points as a set (like equals) or not? The answer is that has to compare every single point. As such, the answer is no. It does not consider points as sets.
"""
from shapely.geometry import LineString

l1 = LineString([[0,0], [1, 1]])
l2 = LineString([[0.01,0.01], [1.0, 1.0]])
l3 = LineString([[0.01,0.01], [1.01, 1.01], [1.01, 1.01]])

print("l1 Almost equals l2 to first digit", l1.almost_equals(l2, 1))
print("l1 does not almost equal l3, because it has an extra point", not l1.almost_equals(l3, 1))
