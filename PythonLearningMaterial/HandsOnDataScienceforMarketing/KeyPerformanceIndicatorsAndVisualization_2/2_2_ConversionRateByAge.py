"""
In this example, we try and break down the conversion rate by age. For this end, we need to group data by age ranges, and then
calculate the number of conversions over the total number of that group.

We can also plot the resulting data easily using the plot function.
"""
import pandas as pd
import matplotlib.pyplot as plt

if __name__ == '__main__':
    df = pd.read_csv("KeyPerformanceIndicatorsAndVisualization_2/bank-additional-full.csv", sep=";")

    df['conversion'] = df['y'].apply(lambda x : 1 if x == 'yes' else 0 )

    grouped_by_age = df.groupby(by='age')

    df_sum_gba = grouped_by_age.sum()
    df_n_gba = grouped_by_age.count()

    conversion_rate = df_sum_gba / df_n_gba * 100

    print("conversion rates by groups:") 
    print(conversion_rate['conversion'])

    ax = conversion_rate['conversion'].plot(
        title='Conversion rate by age group'
        grid=True,
        figsize=(10, 7)
    )
    
    ax.set_xlabel('age')
    ax.set_ylabel('conversion rate')

    plt.show()
