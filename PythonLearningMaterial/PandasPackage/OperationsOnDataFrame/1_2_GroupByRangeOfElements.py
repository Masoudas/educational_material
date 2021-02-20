"""
As we've already seen, groupby groups elements based on repetition in the column for example we're grouping by. So let's say we
have a range of values (like floats) and we want to arrange the column based on if values fall in certain ranges or not, who do
we go about that? This is because [... 0.2 0.201 ...] in a column are not the same floatwise, however they are the same to us
(probably).

The answer is that we need to create a new column using the apply function, based on the ranges we define, and then sort based on
that column. A non-sophisticated example that uses strings is shown below.
"""
import pandas as pd

data = {"c1": [0.2, 0.4, 1.2, 1.4, 2.2, 2.4], "c2": [0.2, 0.4, 1.2, 1.4, 2.2, 2.4]}

df = pd.DataFrame(data=data, copy=True)

df['ranges'] = df["c1"].apply(lambda x : "[0, 1)" if x > 0.0 and x < 1.0 else
                                         "[1, 2)" if x > 1.0 and x < 2.0 else
                                         "[2, 3)" if x > 2.0 and x < 3.0 else
                                         "[3+]")

range_groups = df.groupby(by=['ranges'])

print(range_groups.mean())