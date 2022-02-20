"""
The most fundamental geometric objects are Points, Lines and Polygons which are the basic ingredients when working with spatial data in vector format. Python has a specific module called Shapely for doing various geometric operations. There are many useful functionalities that you can do with Shapely such as:

    -   Create a Line or Polygon from a Collection of Point -geometries
    -   Calculate areas/length/bounds etc. of input geometries
    -   Conduct geometric operations based on the input geometries such as Union, Difference, Distance etc.
    -   Conduct spatial queries between geometries such as Intersects, Touches, Crosses, Within etc.
    
Geometric Objects consist of coordinate tuples where:
    -   Point -object represents a single point in space. Points can be either two-dimensional (x, y) or three dimensional (x, y, z).
    -   LineString -object (i.e. a line) represents a sequence of points joined together to form a line. Hence, a line consist of a list of at least two coordinate tuples
    -   Polygon -object represents a filled area that consists of a list of at least three coordinate tuples that forms the outerior ring and a (possible) list of hole polygons.

It is also possible to have a collection of geometric objects (e.g. Polygons with multiple parts):
    -   MultiPoint -object represents a collection of points and consists of a list of coordinate-tuples
    -   MultiLineString -object represents a collection of lines and consists of a list of line-like sequences
    -   MultiPolygon -object represents a collection of polygons that consists of a list of polygon-like sequences that construct from exterior ring and (possible) hole list tuples
"""
