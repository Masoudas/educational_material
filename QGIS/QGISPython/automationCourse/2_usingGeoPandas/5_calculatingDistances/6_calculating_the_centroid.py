"""
The centroid property of geodataframe can return the center of every polygon. This property returns a Geoseries of center points. What we do is we add it to the geo data frame as a new column, using a direct assignment.
"""

import geopandas as gpd
from shapely.geometry import Point
from pyproj import CRS
import matplotlib.pyplot as plt

fp = "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp"

# Save to disk
data = gpd.read_file(fp)

hki_lon = 24.9417
hki_lat = 60.1666

point = Point(hki_lon, hki_lat)

helsinki = gpd.GeoDataFrame([[point]], geometry='geometry',
                            crs='epsg:4326', columns=['geometry'])

aeqd = CRS(proj='aeqd', ellps='WGS84', datum='WGS84',
           lat_0=hki_lat, lon_0=hki_lon).srs

helsinki = helsinki.to_crs(crs=aeqd)

europe_borders_aeqd: gpd.GeoDataFrame = data.copy()
europe_borders_aeqd.to_crs(crs=aeqd, inplace=True)

europe_borders_aeqd['centroid'] = europe_borders_aeqd.centroid
print(europe_borders_aeqd.head(2))
