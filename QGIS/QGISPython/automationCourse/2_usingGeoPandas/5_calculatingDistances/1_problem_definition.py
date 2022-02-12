"""
In this tutorial, we will calculate distances with projected layers. Our aim is to find the Euclidean distances from the centroids (midpoints) of all European countries to Helsinki, Finland.

We will calculate the distance between Helsinki and other European countries using a metric projection (Azimuthal Equidistant -projection) that gives us the distance in meters. Notice, that this projection is slightly less commonly used, but still useful to know.

Note: For some unGodly reason, the data of Europe borders have longitude first, and then latitude.
This is a bit confusing, but whatever! I guess probably this is a feature of the shape file, that it has longitude first, then latitude.
"""
