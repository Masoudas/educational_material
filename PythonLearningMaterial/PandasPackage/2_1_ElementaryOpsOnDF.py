"""
Data frames can be added, subtracted to, divided by each other, assuming they have the same dimensions. Because data frames
are immutable, a new instance is created every time.

We can also freely add new columns to the data. To add new rows, use the append method of DataFrame. Of course, this would lead
to a new dataframe. We can also append to tables together using the same command.

To print only one column of the table, pass it along to the print function with only the name of that one column.
"""
import pandas as pd

df1 = pd.DataFrame({'c1' : [1, 2, 3], 'c2' : [4, 5, 6]})
df2 = pd.DataFrame({'c1' : [1, 2, 3], 'c2' : [4, 5, 6]})

# Create new dataFrame by summation of two vectors together.
sum_df = df1 + df2 
print(sum_df)

# Add a new column to the existing dataFrame.
sum_df['c3'] = [0, 0, 0]
print(sum_df)

# Add a new row to the table, which results in a new df.
df_appended = sum_df.append({'c1' : 0, 'c2' : 0, 'c3' : 0}, ignore_index = True) # Ignore an index this row may have.
print(df_appended) 

# Appending two tables together
total_appended = df1.append(df2, ignore_index=True)
print(total_appended) 




