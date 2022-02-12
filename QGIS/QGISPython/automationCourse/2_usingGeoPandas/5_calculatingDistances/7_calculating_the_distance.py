"""
Now we have created a new column called centroid that has the Point geometries representing the centroids of each Polygon (in Azimuthal Equidistant projection).

Next, we will calculate the distances between the country centroids and Helsinki. For doing this, we could use iterrows() -function that we have used earlier, but here we will demonstrate a more efficient (faster) technique to go through all rows in (Geo)DataFrame by using the apply() -function.

The apply function is defined below for calculating distances.

Note: Before using our function and calculating the distances between Helsinki and centroids, we need to get the Shapely point geometry from the re-projected Helsinki center point that we can pass to our function (into the dest_geom -parameter. We can use the loc -functionality to retrieve the value from specific index and column.

Now we are ready to use our function with apply(). When using the function, it is important to specify the direction of iteration that should be in our case specified with axis=1. This ensures that the calculations are done row by row (instead of column-wise).

ME: Notice how we use the apply function. The keyword arguments are passed that have the same name as the function arguments. As such, we can pass arguments to our function. We moreover set axis=1 in the APPLY function to ensure that we iterate over rows. Notice that the return statement is important for reassignment. Also notice that apply returns a new dataframe, and it's not in place.
"""
import matplotlib.pyplot as plt
from pyproj import CRS
from shapely.geometry import Point
import geopandas as gpd


def calculate_distance(row, dest_geom, src_col='geometry', target_col='distance'):
    """
    Calculates the distance between Point geometries.

    Parameters
    ----------
    dest_geom : shapely.Point
       A single Shapely Point geometry to which the distances will be calculated to.

    src_col : str
       A name of the column that has the Shapely Point objects from where the distances will be calculated from.

    target_col : str
       A name of the target column where the result will be stored.

    Returns
    -------

    Distance in kilometers that will be stored in 'target_col'.
    """

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
print(europe_borders_aeqd.head(10))
