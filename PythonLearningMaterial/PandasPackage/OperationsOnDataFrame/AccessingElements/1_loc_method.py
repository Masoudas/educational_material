""" 
property: DataFrame.loc
Access a group of rows and columns by label(s) or a boolean array.

loc[] is primarily label based, but may also be used with a boolean array.

Allowed inputs are:
    A single label, e.g. 5 or 'a', (note that 5 is interpreted as a label of the index, and never as an integer position 
    along the index). (Me: Meaning that we can't access the fifth position on an array.)

    A list or array of labels, e.g. ['a', 'b', 'c'].

    A slice object with labels, e.g. 'a':'f'.
    Note that contrary to usual python slices, both the start and the stop are included

    A boolean array of the same length as the axis being sliced, e.g. [True, False, True].

    An alignable boolean Series. The index of the key will be aligned before masking.

    An alignable Index. The Index of the returned selection will be the input.

    A callable function with one argument (the calling Series or DataFrame) and that returns valid output for indexing (one of the 
    above)

    See more at Selection by Label.

Raises:
    KeyError:   If any items are not found.

    IndexingError:  If an indexed key is passed and its index is unalignable to the frame index.

Me: In layman's term:
    In [[], []], the first bracket addresses rows, and the second addresses columns. It returns a new data frame

    In [], Either addresses rows, or columns, returns a time series. It can also be used to address one row and column,

Note that the returned objects used the original dataFrame as backend, hence can be used to assign data to them.
"""
import pandas as pd

df = pd.DataFrame([[1, 2, 10], [4, 5, 3], [7, 8, 1]],
     index=['cobra', 'viper', 'sidewinder'],
     columns=['max_speed', 'shield', 'vision'])

print(df.loc['viper']) # Single label. Note this returns the row as a Series.

# List of labels. Note using [[]] returns a DataFrame.
print(df.loc[['viper', 'sidewinder']])  # We're now accessing two rows
# print(df.loc['viper', 'sidewinder']) This is wrong! Can't have a timeseries of two rows

# Prints the value of these two
print(df.loc['cobra', 'shield'])

# Print the values corresponding to this series of rows and this column
print(df.loc['cobra':'viper', 'max_speed']) 

# Indexing rows. So not first and second row, but only third. Returns all columns in that row
print(df.loc[[False, False, True]])

# A conditional that returns a boolean series
print(df.loc[df['shield'] > 6])

# Even a lambda is fine here 
df.loc[lambda df: df['shield'] == 8]

# Two brackets is used for indexing column and then the row
print(df.loc[[True, True, False],['shield', 'max_speed']])

# Assigning values
df.loc[df['shield'] > 3, ['shield']] = 50
print(df)


# Assigning values to all rows satisfying this property
df.loc[df['shield'] > 3] = 50
print(df)

