"""
We use the read_csv function of Python to read the csv file of bank information.
"""
import pandas as pd
import glob

if __name__ == "__main__":
    # Create a pandas dataframe from the csv file.
    df = pd.read_csv("KeyPerformanceIndicatorsAndVisualization_2/bank-additional-full.csv", sep=";")

    # Defining a new column in the data called 'conversion', by changin the value of the y column.
    df['conversion'] = df['y'].apply(lambda x : 1 if x == 'yes' else 0 )
    
    # Alternatively, we can write
    # df['conversion'] = [1 if x == 'yes' else 0 for x in df['y']]

    # No idea what this one does!
    df.head()

    # Get this! We can access each column of the CSV by just calling it as a field! Then there are operations associated
    # with it such as summation.
    total_num_conversion = df.conversion.sum()
    
    # The first dimension was always the rows, then there was the columns, then third dimension and so on.
    print("Total of %i were converted from a total of %i customers" % (total_num_conversion, df.shape[0]))