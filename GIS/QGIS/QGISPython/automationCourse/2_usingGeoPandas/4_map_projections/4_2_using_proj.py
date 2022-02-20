"""
Here are the information for EPSG3035 and EPSG5150, which is used for Iran (parts of Iran. Search epsg for Iran and you see there are a couple.)

Also note that how we convert them to WKT.
"""
from pyproj import CRS

epsg_3035 = CRS.from_epsg(3035)

print(epsg_3035)
print(epsg_3035.coordinate_system)
print(epsg_3035.axis_info)
print(epsg_3035.datum)
print(epsg_3035.area_of_use.bounds)

# Iran according to European Petroleum ? ? (EPSG)
epsg_2060 = CRS.from_epsg(2060)

print(epsg_2060)
print(epsg_2060.coordinate_system)
print(epsg_2060.axis_info)
print(epsg_2060.datum)
print(epsg_2060.area_of_use.bounds)

print(epsg_2060.to_wkt())
