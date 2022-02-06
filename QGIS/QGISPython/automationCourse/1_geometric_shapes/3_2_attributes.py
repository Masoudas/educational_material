"""
We can also check if we have a “valid” MultiPolygon. MultiPolygon is thought as valid if the individual polygons does notintersect with each other. Here, because the polygons have a common 0-meridian, we should NOT have a valid polygon. We can check the validity of an object from the is_valid -attribute that tells if the polygons or lines intersect with each other. This can be really useful information when trying to find topological errors from your data:

"""
from shapely.geometry import Polygon, Point, MultiPoint, MultiLineString, MultiPolygon, box

multi_point = MultiPoint([])
# Convex Hull of our MultiPoint --> https://en.wikipedia.org/wiki/Convex_hull
convex = multi_point.convex_hull


# How many lines do we have inside our MultiLineString?
multi_line = MultiLineString()
lines_count = len(multi_line)

# Print output:
print("Number of lines in MultiLineString:", lines_count)


west_exterior = [(-180, 90), (-180, -90), (0, -90), (0, 90)]

west_hole = [[(-170, 80), (-170, -80), (-10, -80), (-10, 80)]]
west_poly = Polygon(shell=west_exterior, holes=west_hole)
min_x, min_y = 0, -90
max_x, max_y = 180, 90
east_poly_box = box(minx=min_x, miny=min_y, maxx=max_x, maxy=max_y)

multi_poly = MultiPolygon([west_poly, east_poly_box])

# Let's calculate the area of our MultiPolygon
multi_poly_area = multi_poly.area
print(multi_poly.is_valid)
