"""
3D-point can be recognized from the capital Z -letter in front of the coordinates.
"""
from shapely.geometry import Point, Polygon, LineString

# Create Point geometric object(s) with coordinates
point1 = Point(2.2, 4.2)
point2 = Point(7.2, -25.1)
point3 = Point(9.26, -2.456)
point3D = Point(9.26, -2.456, 0.57)

print(point1)
print(point3D)

# Extracting coordinates
print(point1.coords)

print(point1.x, point1.y)

# Distances
print(point1.distance(point2))
