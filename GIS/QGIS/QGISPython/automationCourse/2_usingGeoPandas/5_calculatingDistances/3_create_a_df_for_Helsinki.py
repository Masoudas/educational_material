""" Notice that we  told that the geometry information is stored in the column called 'geometry' that we actually define with parameter columns=['geometry']
"""
import geopandas as gpd
from shapely.geometry import Point

# Create the point representing Helsinki (in WGS84)
hki_lon = 24.9417
hki_lat = 60.1666

point = Point(hki_lon, hki_lat)

# Dataframes are passed geometric shapes, so as to fill the geometric column.
# Results in
#    geometry
# 0  POINT (24.94170 60.16660)
helsinki = gpd.GeoDataFrame([[point]], geometry='geometry',
                            crs='epsg:4326', columns=['geometry'])
