"""
L2_data folder conaints a layer ne_110m_admin_0_countries.shp that represents the country borders of the world. The data was fownloaded from https://www.naturalearthdata.com/.

"""
import geopandas as gpd
import matplotlib as plt
import matplotlib.pyplot as pyplot
from pyproj import CRS

world = gpd.read_file(
    "QGISPython/automationCourse/2_usingGeoPandas/L2_data/ne_110m_admin_0_countries/ne_110m_admin_0_countries.shp")

# Define projection as web mercator, 3785
web_mercator = CRS.from_epsg(3785)

# Re-project and plot
world.to_crs(web_mercator).plot()

# Remove x and y axis
pyplot.axis('off')
pyplot.title("Web mercator")


ortho = CRS.from_proj4(
    "+proj=ortho +lat_0=60.00 +lon_0=23.0000 +x_0=0 +y_0=0 +a=6370997 +b=6370997 +units=m +no_defs")

# Re-project and plot
world.to_crs(ortho).plot()

# Remove x and y axis
pyplot.axis('off')
pyplot.title("Orthographic")

# Set fig size
plt.rcParams['figure.figsize'] = [12, 6]
world.plot()


pyplot.title("WGS84")
pyplot.show()
