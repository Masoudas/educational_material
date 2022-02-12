"""
Compared to Haversine, Vincenty's formula is very accurate (around 0.5 mm,) but the problem is that it's too expensive.
"""

from shapely.geometry import Point
from vincenty import vincenty
from geopandas import gpd


def measure_distance(row, measure_point: Point, src_col='centroid', target_col='distance'):
    centroid: Point = row[src_col]

    row[target_col] = vincenty(
        tuple(centroid.coords)[0], tuple(measure_point.coords)[0])

    return row


fp = "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp"

# Save to disk
data = gpd.read_file(fp)

hki_lon = 24.9417
hki_lat = 60.1666

helsinki = Point(hki_lon, hki_lat)

europe_borders: gpd.GeoDataFrame = data.copy()
europe_borders['centroid'] = europe_borders.centroid

europe_borders = europe_borders.apply(
    measure_distance, axis=1, measure_point=helsinki, src_col='centroid', target_col='distance_to_hk')

print(europe_borders.head(100))
