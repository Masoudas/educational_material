import geopandas as gpd

# Importing the shape file
data = gpd.read_file(
    "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp")

area_gs: gpd.GeoSeries = data.area
print(area_gs.min(), area_gs.max(), area_gs.median())
