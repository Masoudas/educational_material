"""
Me: With geopandas, we can see the same drives as fiona, because fiona is the library imposed on top of GDAL.

We can see that all data formats can be read as such. Except for example for KML, we need to supply the drives.
"""
import geopandas as gpd

#!!!! Shape file
# Read file from Shapefile
fp = "L2_data/Finland.shp"
data = gpd.read_file(fp)


# Write to Shapefile (just make a copy)
outfp = "L2_data/Finland_copy.shp"
data.to_file(outfp)

#!!!! Geojson file
# Read file from GeoJSON
fp = "L2_data/Finland.geojson"
data = gpd.read_file(fp, driver="GeoJSON")

# Write to GeoJSON (just make a copy)
outfp = "L2_data/Finland_copy.geojson"
data.to_file(outfp, driver="GeoJSON")
