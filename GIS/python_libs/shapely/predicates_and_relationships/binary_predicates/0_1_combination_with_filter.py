"""
Binary predicates can be used directly as predicates for filter() or itertools.ifilter().
"""
from shapely.geometry import LineString, Point

coords = [(0, 0), (1, 1)]

line = LineString(coords)
contained = filter(line.contains, [Point(), Point(0.5, 0.5)])
len(contained) # Returns [Point(0.5, 0.5)]

[p.wkt for p in contained] # prints ['POINT (0.5000000000000000 0.5000000000000000)']