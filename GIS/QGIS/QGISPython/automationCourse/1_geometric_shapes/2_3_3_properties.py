"""
We can access several properties of polygon, as shown below.
"""
from shapely.geometry import Polygon

# First we define our exterior
world_exterior = [(-180, 90), (-180, -90), (180, -90), (180, 90)]

# Let's create a single big hole where we leave ten decimal degrees at the boundaries of the world
# Notice: there could be multiple holes, thus we need to provide a list of holes
hole = [[(-170, 80), (-170, -80), (170, -80), (170, 80)]]

# World without a hole
world = Polygon(shell=world_exterior)

# Now we can construct our Polygon with the hole inside
world_has_a_hole = Polygon(shell=world_exterior, holes=hole)

# Center of the polygon
print(world_has_a_hole.centroid)

# Get the area of the Polygon
print(world.area)

# The length of the exterior
print(world_has_a_hole.exterior.length)
