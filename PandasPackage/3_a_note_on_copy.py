"""
Note that the copy operation on a dataFrame is applicable only if we're making a copy of ANOTHER dataframe. If we're making using
a dictionary or numpy array, then a new backend dataframe is always created

"""
import pandas as pd

data = {"column 1": [1, 2, 3], "column 2" : [4, 5, 6]}
df = pd.DataFrame(data=data, copy=True)
df["column 1"][1] = 10

print(data["column 1"][1])  # Does not affect the dataFrame

############################
# This time around, copy is important.
df1 = pd.DataFrame(data=df, copy=False)
df1["column 1"][1] = 10

# We now see that the content of the original data frame has changed.
print(df["column 1"][1])