"""
Next, we need to convert this GeoDataFrame to “Azimuthal Equidistant” -projection that has useful properties because all points on the map in that projection are at proportionately correct distances from the center point (defined with parameters lat_0 and lon_0), and all points on the map are at the correct direction from the center point.

To conduct the transformation, we are going to utilize again pyproj library which is also good at dealing with “special” projections such as the one demonstrated here.

We will create a CRS by passing specific parameters to Proj() -object that are needed to construct the Azimuthal Equidistant projection:
    *   proj='aeqd' refers to projection specifier that we determine to be Azimuthal Equidistant ('aeqd')
    *   ellps='WGS84' refers to the reference ellipsoid that is a mathematically modelled (based on measurements) surface that approximates the true shape of the world. World Geodetic System (WGS) was established in 1984, hence the name.
    *   datum='WGS84' refers to the Geodetic datum that is a coordinate system constituted with a set of reference points that can be used to locate places on Earth.
    *   lat_0 is the latitude coordinate of the center point in the projection
    *   lon_0 is the longitude coordinate of the center point in the projection

As we can see the projection is indeed centered to Helsinki as the 0-position (in meters) in both x and y is defined now directly into the location where we defined Helsinki to be located (you’ll understand soon better when seeing the map).
"""
import geopandas as gpd
from pyproj import CRS
from shapely.geometry import Point

hki_lon = 24.9417
hki_lat = 60.1666

point = Point(hki_lon, hki_lat)

helsinki = gpd.GeoDataFrame([[point]], geometry='geometry',
                            crs='epsg:4326', columns=['geometry'])


# Define the projection using the coordinates of our Helsinki point (hki_lat, hki_lon) as the center point The .srs here returns the text presentation of the projection
aeqd = CRS(proj='aeqd', ellps='WGS84', datum='WGS84',
           lat_0=hki_lat, lon_0=hki_lon).srs

# Reproject to aeqd projection using Proj4-string
helsinki = helsinki.to_crs(crs=aeqd)

# Print the data
print(helsinki)

# Print the crs
print('\nCRS:\n', helsinki.crs)
