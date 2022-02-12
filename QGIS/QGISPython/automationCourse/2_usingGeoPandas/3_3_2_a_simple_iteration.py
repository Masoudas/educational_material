"""
The column geometries contains the most important information, which is geomteries.
"""
from shapely.geometry import Polygon
import geopandas as gpd

# Importing the shape file
data = gpd.read_file(
    "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp")

for index, row in data[0:5].iterrows():
    print(row['geometry'])

    # Alternatively
    #polygon = Polygon(row['geometry'])
    # print(row['geometry'].area)
