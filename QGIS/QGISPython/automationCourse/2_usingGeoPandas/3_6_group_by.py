"""
Just like a normal data base, we can use the groupby function to group a table rows.

For example below, we group by the unique records pf TZID
"""
import geopandas as gpd

# Importing the shape file
data = gpd.read_file(
    "QGISPython/automationCourse/2_usingGeoPandas/L2_data/Europe_borders.shp")

unique_keys = data["TZID"].unique()
grouped_df = data.groupby(by="TZID")

print(unique_keys)
# Another way of getting the keys. Note that this is the keys method of a dictionary
print(grouped_df.groups.keys())

# Print the dataframe that corresponds to one of the groups.
print(grouped_df.get_group(unique_keys[1]))


# Iterate over the group object
for key, group in grouped_df:

    # Let's check how many rows each group has:
    print('Terrain class:', key)
    print('Number of rows:', len(group), "\n")
