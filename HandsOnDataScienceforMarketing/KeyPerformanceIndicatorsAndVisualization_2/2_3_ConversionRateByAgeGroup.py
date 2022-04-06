"""
In the previous exercise, the age groups consisted of those who had a particlar age (18, 19, ..., 70, etc). In this exercise, we
try and plot the conversion rate for each age group.

Note that group_by can't exactly group for intervals. So instead what we do (oddly enough), is to add a new column to the table
indicating the age range a row belongs to. This column is called age_range, and it has [18, 30), [30, 40), [40, 50), [50, 60),
[60, 70), 70+.

After doing so, we just need to group the age groups together, then calculate the sum and count, then divide these two, and then
plot the results.

To plot the results, we supply a 'kind' option to the plot method of data row. To ensure the order of the data we plot, we use
the loc method, which gets the location order of data.
"""
import pandas as pd
import matplotlib.pyplot as plt

if __name__ == '__main__':
    df = pd.read_csv("KeyPerformanceIndicatorsAndVisualization_2/bank-additional-full.csv", sep=";")

    df['conversion'] = df['y'].apply(lambda x : 1 if x == 'yes' else 0 )

    df['age_group'] = df['age'].apply(lambda x : '[18, 30)' if x >= 18 and x < 30 else
                                                  '[30, 40)' if x >= 30 and x < 40 else  
                                                  '[40, 50)' if x >= 40 and x < 50 else  
                                                  '[50, 60)' if x >= 50 and x < 60 else
                                                  '[60, 70)' if x >= 60 and x < 70 else 
                                                  '[60, 70)' if x >= 60 and x < 70 else
                                                  '70+')

    conversion_by_age_group = df.groupby(by=['age_group'])['conversion']
    conv_rate_by_age_group = conversion_by_age_group.sum() / conversion_by_age_group.count()

    print(conv_rate_by_age_group)

    # Why do we need the loc function here? So that we can order the columns in the way we desire. Otherwise,
    # 70+ would have been the first column. Also, notice the bracket inside the bracket, which allow us to have
    # a dataframe that has the original dataFrame as backend.
    ax = conv_rate_by_age_group.loc[['[18, 30)', '[30, 40)', '[40, 50)', '[50, 60)', '[60, 70)', '70+']].plot(
        kind='bar',
        color='skyblue',
        grid=True,
        figsize=(10, 7),
        title='Conversion Rates by Age Groups'
    )

    ax.set_xlabel('age')
    ax.set_ylabel('conversion rate (%)')

    plt.show()

