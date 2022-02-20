"""
Luckily, defining and changing projections is easy in Geopandas. In this tutorial we will see how to retrieve the coordinate reference system information from the data, and how to change the crs. We will re-project a data file from WGS84 (lat, lon coordinates) into a Lambert Azimuthal Equal Area projection which is the recommended projection for Europe by European Commission.


In Shapefiles, information about the coordinate reference system i stored in the .prj -file (if this file is missing, you might be in trouble!). When reading the data into GeoDataFrame with Geopandas crs information is automatically stored into the .crs attribute of the GeoDataFrame,
which in this case is "epsg:4326". The EPSG number (named after the European Petroleum Survey Group) is a code that tells about the coordinate system of the dataset. “EPSG Geodetic Parameter Dataset is a collection of definitions of coordinate reference systems and coordinate transformations which may be global, regional, national or local in application”.

The EPSG code of our geodataframe is 4326, which refers to the WGS84 coordinate system (we can also figure this out by looking at the coordinate values which are longitude and latitudes decimal degrees).

You can find a lot of information and lists of available coordinate reference systems from:

www.spatialreference.org
www.proj4.org
www.mapref.org

Indeed, if we look at our data, we see that the coordinates of the polygon are latitude and longitude to decimal degrees.
"""
import geopandas as gpd

data = gpd.read_file(
    "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp")

print(data.crs)
