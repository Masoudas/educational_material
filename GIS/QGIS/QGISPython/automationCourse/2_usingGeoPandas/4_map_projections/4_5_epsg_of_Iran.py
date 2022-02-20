"""
Apparently (and thanks to Mr. Hekmat!) the EPSG for Iran is 32639.
"""
from pyproj import CRS

Iran_CRS = CRS.from_epsg(32639)
print(Iran_CRS.area_of_use)
