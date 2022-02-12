"""
Me: At this point, we convert the borders into our frame of reference, where the center is put on Helsinki.

Okay, now we can see that the coordinates in geometry column are fairly large numbers as they represents the distance in meters from Helsinki to different directions.

As we can see from the map, the projection is indeed centered to Helsinki as the 0-position of the x and y axis is located where Helsinki is positioned. Now the coordinate values are showing the distance from Helsinki (black point) to different directions (South, North, East and West) in meters.
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

print(europe_borders_aeqd.head(2))
#       TZID                                  geometry
# 0  Europe/Berlin  POLYGON ((-1057542.597 -493724.802, -1058052.5...
# 1  Europe/Berlin  POLYGON ((-1216418.435 -1243831.635, -1216378....

fig, ax = plt.subplots(figsize=(10, 10))

# Plot the country borders
europe_borders_aeqd.plot(ax=ax)

# Plot the Helsinki point on top of the borders using the same axis
helsinki.plot(ax=ax, color='black', markersize=10)
plt.show(block=True)
