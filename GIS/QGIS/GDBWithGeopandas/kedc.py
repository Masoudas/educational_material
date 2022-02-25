import geopandas as gpd
import fiona
import matplotlib.pyplot as plt
from numpy import block

file = "/home/masoud/Documents/SircoProjects/faham_gis/resources/main/KhorasanGIS/kedc_gis.gdb"

# Getting the list of all layers available in this database
layers = fiona.listlayers(file)
for layer in layers:
    print(layer)
   # layer = gpd.read_file(file, layer=layer)
   # print(layer.columns)

# Listing the feaure classes, topoligies, networks, etc in the class.
khorasan_items = gpd.read_file(file, layer='GDB_Items')
print(khorasan_items.columns)
print(khorasan_items)

# Listing the type of feaure classes, topologies, networks, etc in the class.
khorasan_itemTypes = gpd.read_file(file, layer='GDB_ItemTypes')
print(khorasan_itemTypes.columns)
print(khorasan_itemTypes)
