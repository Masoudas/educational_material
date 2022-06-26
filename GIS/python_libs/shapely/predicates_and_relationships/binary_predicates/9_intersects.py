"""
Returns True if the boundary or interior of the object intersect in any way with those of the other.

Exercise: Consider the line (0,0)->(1,1), and then the line (0.5,0.5)->(1,0). Obviously, we know that these two lines intersect one another. Question is, can we check that these are not consecutive lines, meaning one line branches from the other (in the middle of it?) This check must say that the line (1,1)->(2,2) does not branch, but is rather at the end of the other line?
The answer is yes, we can use the boundary object to do so. This is of course equivalent to TOUCHES!
"""
from shapely.geometry import LineString, Point

coords = [(0, 0), (1, 1)]

# Note that [0.5, 0.5], [1, 0] intersecs, but its boundary does not. Hence, this line is a branch from the other!
print(LineString(coords).boundary.intersects(LineString([[0.5, 0.5], [1, 0]]))) # false
print(LineString(coords).intersects(LineString([[0.5, 0.5], [1, 0]]))) # true


# On the other hand, this is true for both, so, we conclude that these are consecutive lines segments that can be merged.
print(LineString(coords).boundary.intersects(LineString([[0.5, 0.5], [1, 0]]))) # true
# print(LineString(coords).intersects(LineString([[0.5, 0.5], [1, 0]]))) # This check is not needed then.