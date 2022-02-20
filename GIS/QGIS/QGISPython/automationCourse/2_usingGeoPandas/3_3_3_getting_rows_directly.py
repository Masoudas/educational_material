"""We may further calculate the area for each polygon directly"""

from shapely.geometry import Polygon
import geopandas as gpd

# Importing the shape file
data = gpd.read_file(
    "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp")

print(data.area.head())

area_df: gpd.GeoSeries = data.area
# A new series, with only an indexer and a column named area
print(area_df.name)
print(area_df.head())
