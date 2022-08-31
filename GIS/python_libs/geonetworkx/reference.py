"""
https://geonetworkx.readthedocs.io/en/latest/
"""
import geonetworkx as gnx
import networkx as nx
from shapely.geometry import MultiLineString, MultiPoint
from shapely.ops import split, linemerge
import matplotlib.pyplot as plt
import geopandas as gpd
import momepy

air_lines: gpd.GeoDataFrame = gpd.read_file(
    "geonetworkx/Saghravan_Senobar_MV_Air/Saghravan_Senobar_MV.shp", crs=3857)
air_lines.to_crs(4326, inplace=True)
air_lines = [line[1].geometry for line in air_lines.iterrows()]

ground_lines: gpd.GeoDataFrame = gpd.read_file(
    "geonetworkx/Saghravan_Senobar_MVGRD/SS_MVGRD.shp", crs=3857)
ground_lines.to_crs(4326, inplace=True)
ground_lines = [line[1].geometry for line in ground_lines.iterrows()]
  

jmpr_lines: gpd.GeoDataFrame = gpd.read_file(
    "geonetworkx/Saghravan_Senobar_JMPR/SS_JMPR.shp", crs=3857)
jmpr_lines.to_crs(4326, inplace=True)
jmpr_lines = [line[1].geometry for line in jmpr_lines.iterrows()]

all_lines = air_lines
all_lines.extend(ground_lines)
all_lines.extend(jmpr_lines)


mLines = MultiLineString(all_lines)

fuses = gpd.read_file(
    "geonetworkx/Saghravan_Senobar_Fuse_Cout/Saghravan_Senobar_Fuse_Cout.shp", 
    crs=3857)[['EDS_ID','geometry']]
fuses = fuses.to_crs(4326)
fuses = MultiPoint([fuse[1].geometry for fuse in fuses.iterrows()])

graph_edges = split(mLines, fuses)
graph_edges_df = gpd.GeoDataFrame(
    data=[{"geometry": edge, "index": i} for i, edge in enumerate(graph_edges)])

graph = momepy.gdf_to_nx(graph_edges_df, approach='primal')

print(nx.is_connected(graph))

f, ax = plt.subplots(1, 2, figsize=(18, 6), sharex=True, sharey=True)
graph_edges_df.plot(color='#e32e00', ax=ax[0])

for i, facet in enumerate(ax):
    facet.set_title(("all_lines", "Primal graph", "Overlay")[i])
    facet.axis("off")

nx.draw(graph, {n:[n[0], n[1]] for n in list(graph.nodes)}, ax=ax[1], node_size=15)

# graph_edges_df.plot(color='#e32e00', ax=ax[2], zorder=-1)

# nx.draw(graph, {n:[n[0], n[1]] for n in list(graph.nodes)}, ax=ax[2], node_size=15)
plt.show(block=True)
ax.scatter()