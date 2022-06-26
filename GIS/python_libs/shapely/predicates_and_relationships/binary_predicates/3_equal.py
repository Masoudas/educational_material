"""
Returns True if the set-theoretic boundary, interior, and exterior of the object coincide with those of the other.

Me: What does this imply? It implies that coordinates are considered as sets , and redundant points are as such removed.

Me: What about reverse lines? Yes. This is because it considers objects as sets, and as such, the reverse of a set is equal to that set.
"""
from shapely.geometry import LineString

l1 = LineString([[0,0], [1, 1]])
l2 = LineString([[0,0], [1, 1], [1, 1]])
l3 = LineString([[0,0], [1, 1]])
rl2 = LineString([[1, 1], [0,0]])

print("l1 equals l3:", l1.equals(l3))
print("l1 DOES equal l2 with equal, but not with __eq__:", l1.equals(l2))

print("reverse of l1 is equal to it:", l1.equals(rl2))

