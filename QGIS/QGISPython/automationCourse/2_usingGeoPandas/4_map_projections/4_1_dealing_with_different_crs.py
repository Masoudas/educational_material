"""
There are various ways to present Coordinate Reference System information, such as PROJ strings, EPSG codes, Well-Known-Text (WKT), JSON. It is likely that you will encounter some of these when working with spatial data obtained from different sources. Being able to convert the CRS information from one format to another is needed every now and then, hence, it is useful to know a few tricks how to do this.

Luckily, dealing with CRS information is easy in Python using a library called pyproj. In fact, pyproj is a Python wrapper around a software called PROJ (maintained by OSGeo community), which is widely used tool for conducting coordinate transformations in various GIS softwares. Pyproj is also used under the hood in Geopandas, and it handles all the CRS definitions and coordinate transformations (reprojecting from CRS to another as we did earlier).

Next, let’s see how it is possible to easily extract useful information from CRS, and transform CRS information from one format to another. pyproj -library has a class called CRS that provides many useful functionalities for dealing with CRS information.
"""

