import geopandas as gpd
import fiona
import matplotlib.pyplot as plt
from numpy import block

file = "/home/masoud/Documents/SircoProjects/faham_gis/resources/main/KhorasanGIS/kedc_gis.gdb"

# Getting the list of all layers available in this database
layers = fiona.listlayers(file)
for layer in layers:
    print(layer)

khorasan_ct = gpd.read_file(file, layer='GDB_Version')
print(khorasan_ct.columns)
print(khorasan_ct)

# Listing a particular layer
khorasan_ct = gpd.read_file(file, layer='GDB_Layers')
print(khorasan_ct.columns)
print(khorasan_ct)

khorasan_Metadata = gpd.read_file(file, layer='lyr_earth_sys')
print(khorasan_Metadata.columns)
print(khorasan_Metadata)

"""
lyr_a_meter
lyr_auto_switch
lyr_busbar
lyr_circt_brk
lyr_contactor
lyr_ct
lyr_cut_out
lyr_discnt_s
lyr_dist_tr
lyr_distrb_box
lyr_earth_sys
lyr_flt_indc
lyr_fuse_switch
lyr_hv_substate
lyr_hv_transformer
lyr_lv_cable_joint
lyr_lv_cpacitor
lyr_lv_isolator
lyr_lv_jumper
lyr_mof
lyr_mv_cable_joint
lyr_mv_cpacitor
lyr_mv_isolator
lyr_mv_jumper
lyr_oh_lv_line
lyr_oh_mv_line
lyr_pd_mdsub
lyr_pg_mdsub
lyr_pt
lyr_recloser
lyr_sectionalizer
lyr_subscriber
lyr_subscriber_cable
lyr_ug_lv_line
lyr_ug_mv_line
lyr_v_meter
"""
