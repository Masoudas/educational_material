"""
One other thing we can look at is the demographic differences between the converted clients and non-converted clients.
This type of analysis can help us identify what differentiates converted groups from non-converted groups in our marketing 
campaigns and help us understand our target clients better and what types of customers respond better to our marketing efforts. 
In this exercise, we will compare the distributions of the marital status among the conversions and non-conversions groups.

The issue with this examination is that it's a second ordered statistics, meaning we need to look at the fact a person is 
converted and their marital status. For such situation, use of pivot function is helpful.

If we don't want to do that, we have to group by one statistic, and then use that to calculate the second statistic, which is
essentially what I do.

"""
import pandas as pd
import matplotlib.pyplot as plt

if __name__ == "__main__":
    df = pd.read_csv(filepath_or_buffer="./KeyPerformanceIndicatorsAndVisualization_2/bank-additional-full.csv",sep=";")

    df['conversion'] = df['y'].apply(lambda x : 1 if x == 'yes' else 0 )

    ## My approach is to group by converted and non-converted, and then count the number of married people among each group.
    # grouping by conversion
    conversion_groups = df.groupby(by=['marital'])
    group_converted = conversion_groups["conversion"].sum()
    group_unconverted = conversion_groups["conversion"].count() - group_converted
    group_unconverted = group_unconverted.rename("non-conversion")
    
    combined_groups = pd.concat([group_unconverted, group_converted], axis=1)
    print(combined_groups)
    
    # Pivot the table in such a way that marital is the index and columns are conversions.
    conversions_by_marital_status_df = pd.pivot_table(df, values='y', index='marital', columns='conversion', aggfunc=len)
    print(conversions_by_marital_status_df)

    conversions_by_marital_status_df.plot(
    kind='pie',
    figsize=(15, 7),
    startangle=90,
    subplots=True,
    autopct=lambda x: '%0.1f%%' % x
    )

    plt.show()
    
    
    