"""
DataFrame.groupby(by=None, axis=0, level=None, as_index=True, sort=True, group_keys=True, observed=False, dropna=True)

A groupby operation involves some combination of splitting the object, applying a function, and combining the results. This can be 
used to group large amounts of data and compute operations on these groups.

by: mapping, function, label, or list of labels
Used to determine the groups for the groupby. If by is a function, it’s called on each value of the object’s index. If a dict or 
Series is passed, the Series or dict VALUES will be used to determine the groups (the Series’ values are first aligned; 
see .align() method). If an ndarray is passed, the values are used as-is to determine the groups. A label or list of labels may 
be passed to group by the columns in self. Notice that a tuple is interpreted as a (single) key.

axis: {0 or ‘index’, 1 or ‘columns’}, default 0
Split along rows (0) or columns (1).

level: int, level name, or sequence of such, default None
If the axis is a MultiIndex (hierarchical), group by a particular level or levels.

as_index: bool, default True
For aggregated output, return object with group labels as the index. Only relevant for DataFrame input. as_index=False is 
effectively “SQL-style” grouped output.

sort: bool, default True
Sort group keys. Get better performance by turning this off. Note this does not influence the order of observations within 
each group. Groupby preserves the order of rows within each group.

group_keys: bool, default True
When calling apply, add group keys to index to identify pieces.

observed: bool, default False
This only applies if any of the groupers are Categoricals. If True: only show observed values for categorical groupers. 
If False: show all values for categorical groupers.

dropna: bool, default True
If True, and if group keys contain NA values, NA values together with row/column will be dropped. If False, NA values will also be 
treated as the key in groups


"""
import pandas as pd
import numpy as np

df = pd.DataFrame({'Animal': ['Falcon', 'Falcon',
                              'Parrot', 'Parrot'],
                   'Max Speed': [380., 370., 24., 26.]})

# Groups by the name of the animal and returns a new groupby object. In and of itself, this object holds all the (rows)
# containing the same information. But because no operation is defined on it, we can't show it as an object (how can we show
# all the rows in a group directly?!). Hence, we need to define some statistic on the group.
# It's very cool that it's able to group all the similar items together without me telling it anything.
animal_groups = df.groupby(['Animal'])
print(animal_groups)

# First quantile of the speed of each animal group. 
first_quantile_animal_group = animal_groups.quantile(q=0.25)
print(first_quantile_animal_group)

# Max of each group
max_animal_group = animal_groups.max()
print(max_animal_group)

#####################################################
data = l = [["a", 12, 12], [None, 12.3, 33.], ["b", 12.3, 123], ["a", 1, 1]]
df =  pd.DataFrame(l, columns=["c1", "c2", "c3"])

# Drop the nones from the data frame and print the mean of each group
print(df.groupby(by=["c1"], dropna=True).mean()) 

#####################################################
# To generate more complex statistics, note that we can divide, add, subtract and multiply two group results together.
percentage_df = df.groupby(by=["c1"], dropna=True).sum() / df.groupby(by=["c1"], dropna=True).count()

############################################
