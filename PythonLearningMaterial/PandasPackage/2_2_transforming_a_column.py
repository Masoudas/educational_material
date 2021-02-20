"""
To transform a column in a data frame, we can either treat it as a dictionary, and then write a for loop for it, or we can use the
apply function to change that frame. Note that with both operations, we can add a new column as well.

Note that the apply function works on each row, and it accepts a lambda. The apply method does not affect the column it's operating
on, rather it Generates a new column
"""

import pandas as pd

df = pd.DataFrame({'c1' : [1, 2, 3], 'c2' : [4, 5, 6]})

# Transforming the column
df['c1'] = df['c1'].apply(lambda x : x * 10)

# Creating a new column
df['c2'] = df['c1'].apply(lambda x : x / 10)
print(df)

# Direct munipulation of column elements also work.
df['c2'] = [x - 10 for x in df['c2']]
print(df)