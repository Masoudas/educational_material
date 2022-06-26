"""
Returns True if the geometries have more than one but not all points in common, have the same dimension, and the intersection of the interiors of the geometries has the same dimension as the geometries themselves.

ME: A line can't overlap a polygon, because it does not have the same dimension (it can cross it, or intersect it.) A point does not overlap a line. Two polygons may overlap, assuming they have more than one point in common (because a single point only implies intersection.) Two lines may overlap, assuming they have an overlapping portion.

ME: About the interior having the same dimension, for example two lines that intersect only on one point have one dimension less in their interior's intersection.
"""