"""
Returns True if the interior of the object intersects the interior of the other but does not contain it, and the dimension of the intersection is less than the dimension of the one or the other.

Me: For example, if two lines cross each other on their centers, then their interiors intersect each other, and the dimension of intersection is 1 (a point.) However, if one line touches the other at its end point, then this is not a crossing, because the crossing does not happen on the interior! 

Me: A point does not cross a line! Why? Because a point can't go beyond it. This is the reason why a point on a line does not cross it. This is cool! As Mr. Gholizade just said, if this were not the case, then any intersect would have been a cross!
"""
from shapely.geometry import LineString, Point

coords = [(0, 0), (1, 1)]

# This is true
print(LineString(coords).crosses(LineString([[0, 1.0], [1.0, 0]])))

# This is False, because not on interior
print(LineString(coords).crosses(LineString([[-1, -1], [0, 0]])))

# This is also false, because 
print(LineString(coords).crosses(Point([0.5, 0.5])))
