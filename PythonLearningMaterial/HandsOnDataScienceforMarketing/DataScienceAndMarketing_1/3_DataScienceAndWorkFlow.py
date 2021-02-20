"""
Every problem in the field of data science more or less follows the following workflow:

1- Problem definition: Typically, any data science and machine learning project starts with problem definition. In this first step, 
   you need to define the problems that you are trying to solve with data science, the scope of the project, and the approaches to 
   solving this problem. When you are thinking about some of the approaches to solving your problem, you will need to brainstorm on 
   what types of analyses (descriptive versus explanatory versus predictive) and types of learning algorithms (supervised versus 
   unsupervised versus reinforcement learning) that we discussed previously will be suitable for solving the given problem.

2- Data collection:  Once you have a clear definition of the project, you will then move on to the data collection step. This is 
   where you gather all the data you need to proceed with your data science project. It is not uncommon that you will need to 
   purchase data from third-party vendors, scrape and extract data from the web, or use publicly available data. In some cases, 
   you will also need to collect data from your internal systems for your project. Depending on the cases, the data collection 
   step can be trivial or it can also be tedious.

3- Data preparation: When you have gathered all of the data you need from the data collection step, then the next step is data 
   preparation. The goal of this step is to transform your data and prepare it for future steps. If the formats of the data sources 
   are different, then you will have to transform and unify the data. If the data doesn't have a certain structure, then you will 
   have to structure the data, typically in tabular format, so that you can easily conduct different analyses and build machine 
   learning models.

4- Data analysis: When you are done with the data preparation step, then you will have to start looking into the data. In the data 
   analysis step, typically, descriptive analyses are conducted to compute some descriptive summary statistics and build visual 
   plots to better understand the data. Quite often, you can find some recognizable patterns and draw some insight from data during 
   this step. You may also be able to find any anomalies in the data, such as missing values, corrupted data, or duplicate records, 
   from this step.

5- Feature engineering: Feature engineering is the most important part of data science and machine learning, as it directly affects 
   the performance of predictive models. Feature engineering requires expertise and good domain knowledge of the data, as it 
   requires you to transform the raw data into more informative data for your algorithms to learn from. One good example of feature 
   engineering is transforming text data into numerical data. As the machine learning algorithms can only learn from numerical data, 
   you will need to come up with an idea and strategy to translate textual data into numerical data. As we work through this book 
   and as we build machine learning models, we will discuss and experiment with various feature engineering techniques.

6- Model building: Once you are done with the feature engineering step, then you can start training and testing your machine 
   learning models. In this step, you can experiment with various learning algorithms to figure out which one works the best for 
   your use case. One thing to keep in mind in this step is the validation metrics. It is important to have a good measure of your 
   model performance, as machine learning algorithms will try to optimize on the given performance measure. As we start building 
   machine learning models in the following chapters, we will discuss more in detail regarding what metrics to use depending on the 
   type of problems that we are working on.

Note that this process is iterative and once we're on step 6, we may have to go back to step 2 to refine our data from start.
"""