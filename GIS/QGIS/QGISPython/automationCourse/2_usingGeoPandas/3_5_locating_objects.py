"""
In this example, we filter a particular object type, and then, we save it as another shape file.

Notice that it's also possible to replace after locating. Notice that the column we want to replace must be given as the second argument of loc
"""
import geopandas as gpd

# Importing the shape file
data = gpd.read_file(
    "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp")

stockholm: gpd.GeoDataFrame = data.loc[lambda df: df['TZID']
                                       == "Europe/Stockholm"]
print(stockholm)

data.loc[lambda df: df['TZID'] == "Europe/Stockholm", ['TZID']] = "Stockholm"
print(data)

# Writing the new shape file if desired.
# data.to_file("new_file.shp")
