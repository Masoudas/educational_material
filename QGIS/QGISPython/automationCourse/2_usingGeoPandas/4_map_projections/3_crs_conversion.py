"""
EPSG4326 is not really good for representing borders in Euro. As such, we shall change our coordinate system to Lambert Azimuthal Equal Area projection (EPSG: 3035) which is the recommended projection by European Comission.

We need to merely use to_crs in our case.

It would actually be very interesting to compare the resulting figures.
"""
from geopandas import gpd
import matplotlib.pyplot as plt

data: gpd.GeoDataFrame = gpd.read_file(
    "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp"
)

new_crs = data.to_crs(epsg=3035, inplace=False)

axis = data.plot()
axis_new = new_crs.plot()

axis.set_xlabel("EPSG 4326")
axis_new.set_xlabel("EPSG 3035 (Lambert)")


plt.show(block=True)
