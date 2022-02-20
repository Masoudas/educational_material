"""
We can see the longest and shortest distances after our final calculation.
"""
import matplotlib.pyplot as plt
from pyproj import CRS
from shapely.geometry import Point
import geopandas as gpd


def calculate_distance(row, dest_geom, src_col='geometry', target_col='distance'):
    # Calculate the distances
    dist = row[src_col].distance(dest_geom)

    # Convert into kilometers
    dist_km = dist / 1000

    # Assign the distance to the original data
    row[target_col] = dist_km
    return row


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

# Retrieve the geometry from Helsinki GeoDataFrame
helsinki_geom = helsinki.loc[0, 'geometry']  # This would be of course [0, 0]

# Calculate the distances using our custom function called 'calculate_distance'
europe_borders_aeqd = europe_borders_aeqd.apply(
    calculate_distance, axis=1, dest_geom=helsinki_geom, src_col='centroid',
    target_col='dist_to_Hki')

# Calculat the maximum and average distance
max_dist = europe_borders_aeqd['dist_to_Hki'].max()
mean_dist = europe_borders_aeqd['dist_to_Hki'].mean()
