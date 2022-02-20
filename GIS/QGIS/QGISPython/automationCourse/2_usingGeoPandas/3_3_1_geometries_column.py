"""
The column geometries contains the most important information, which is geomteries.
"""
import geopandas as gpd

# Importing the shape file
data = gpd.read_file(
    "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp")

# geometry of the first row (How did they implement this?)
print("Polygon", data.at[0, "geometry"])

# Of course, some fundamental methods are already supplied
print("Area", data.at[0, "geometry"].area, "square meters")

