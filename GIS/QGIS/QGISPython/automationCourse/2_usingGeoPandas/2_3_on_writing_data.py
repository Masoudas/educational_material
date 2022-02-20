"""
For example, note that if we wanted to save a particular layer, we could pass the name of that layer.
"""

import geopandas as gpd

# Read file from File Geodatabase
fp = "L2_data/Finland.gdb"
data = gpd.read_file(fp, driver="FileGDB", layer='country')

# Write to same FileGDB (just add a new layer)
outfp = "L2_data/Finland.gdb"
data.to_file(outfp, driver="FileGDB", layer="country_copy")
