"""
Geopandas (http://geopandas.org/) makes it possible to work with geospatial data in Python in a relatively easy way. Geopandas combines the capabilities of the data analysis library pandas with other packages like shapely and fiona for managing spatial data.

The main data structures in geopandas; GeoSeries and GeoDataFrame extend the capabilities of Series and DataFrames from pandas. This means that we can apply our pandas skills also with geopandas data structures. If you need to refresh your memory about pandas, check out week 5 and 6 lesson materials from the Geo-Python website.

The main difference between geodataframes and pandas dataframes is that a geodataframe should contain one column for geometries (by default, the name of this column is 'geometry'). The geometry column is a geoseries which contains the geometries (points, lines, polygons, multipolygons etc.) for each row of data.
"""
from shapely.geometry import Polygon
import geopandas as gpd

# Importing the shape file
data = gpd.read_file(
    "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp")

# The geometry of objects must always be present
print(data['geometry'])

# First polygon geometry.
first_polygon = Polygon(data['geometry'][0])
print(first_polygon.area)   # Does seem to work!

# Printing the head of the data (first couple of rows)
print(data.head())

print("Name of the columns are", data.columns)

# Renaming columns
new_names = {'TZID': "Column1", "geometry": "geometry"}
data.rename(columns=new_names, inplace=True)
print(data.columns)


# Number of rows. For that we need to get a row and calculate its length.
print(len(data['Column1']))

# Number of unique rows for each column, or alternatively:
print(data.nunique(0))
print(data['Column1'].nunique(), data['geometry'].nunique())
