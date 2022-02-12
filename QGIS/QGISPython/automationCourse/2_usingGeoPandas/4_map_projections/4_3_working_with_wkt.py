"""
We can get the CRS from a WKT file, as the following example demonstrates.

As we can see, the WKT format contains a lot of information. Typically, e.g. the .prj file of a Shapefile contains the information in this format. 
"""
from pyproj import CRS

# Creating a wkt
crs = CRS.from_epsg(2060)
wkt = crs.to_wkt()

# Get epsg from wkt
epsg = CRS.from_wkt(wkt).to_epsg()
