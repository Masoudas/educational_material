from shapely.geometry import LineString, Point

# Create a LineString from our Point objects
point1 = Point(2.2, 4.2)
point2 = Point(7.2, -25.1)
point3 = Point(9.26, -2.456)

line = LineString([point1, point2, point3])

# It is also possible to produce the same outcome using coordinate tuples
line2 = LineString([(2.2, 4.2), (7.2, -25.1), (9.26, -2.456)])

# getting line coordinates
line_xcoords = line2.xy[0]
line_ycoords = line2.xy[1]

print(line_xcoords)
print(line_ycoords)


# Get length of line
print(line2.length)

# Get center of line
print(line2.centroid)
