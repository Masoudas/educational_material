"""
Important note from me: It's important to note that the centroid MUST NOT be calculated with latitude and longitude. Instead, we have to convert using a CRS. Then, we need to convert back to lattitude and longitude. How do we do the latter? The answer is using Transform from pyproj.

Question is, what is the latitude and longitude coordinate system? The answer is that it's EPSG 4326, which is equivalent to WGS84. We could have also guessed it without an Internet search by just getting the EPSG of the borders.
"""

from shapely.geometry import Point
from haversine import haversine, Unit
from geopandas import gpd
import pyproj


def measure_distance(row, measure_point: Point, src_col='centroid', target_col='distance'):
    centroid: Point = row[src_col]

    row[target_col] = haversine(
        tuple(centroid.coords)[0], tuple(measure_point.coords)[0], Unit.KILOMETERS)

    return row


proj = pyproj.Transformer.from_crs(3035, 4326, always_xy=True)


def convert_to_latitude_longitude(row, src_col='centroid', target_col='centroid'):
    centroid: Point = row[src_col]

    longitude, latitude = proj.transform(centroid.x, centroid.y)
    row[target_col] = Point(latitude, longitude)
    return row


fp = "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp"

# Save to disk
data = gpd.read_file(fp)

hki_lon = 24.9417
hki_lat = 60.1666

helsinki = Point(hki_lat, hki_lon)

europe_borders: gpd.GeoDataFrame = data.copy()

# To get the original crs
print(europe_borders.crs)

# Calculating the centroid
centroid_calc = europe_borders.to_crs(epsg=3035)
centroid_calc['centroid'] = centroid_calc.centroid


centroid_calc = centroid_calc.apply(
    convert_to_latitude_longitude, axis=1, src_col='centroid', target_col='centroid')

centroid_calc = centroid_calc.apply(
    measure_distance, axis=1, measure_point=helsinki, src_col='centroid', target_col='distance_to_hk')

print(centroid_calc.head(10))
