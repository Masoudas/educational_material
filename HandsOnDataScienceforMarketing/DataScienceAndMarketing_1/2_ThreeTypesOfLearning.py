"""
In simpleton terms, unsupervised learning is what Hamed was doing For Dr. Benari, hoping the machine would cluster the data without
any aid from the human. Supervised learning aides the machine in extracting the information we need from the data, not letting it
cluster the data the way it sees fit. Reinforcement learning constantly uses past information to perdict the future outcome and
then improves the future predictions. Here's a more detailed explaination:

Supervised learning algorithms: These algorithms are used when the prediction target or outcome is known. For example, if we want 
to use machine learning to predict who will make purchases in the next few days, then we will use supervised learning algorithms. 
Here, the prediction target or outcome is whether this person made a purchase within the given time window or not. Based on the 
historical purchase data, we will need to build features, which describe each data point, such as a user's age, address, last 
purchase date, and then supervised learning algorithms will learn from this data how to map these features to the prediction target 
or outcome.

Unsupervised learning algorithms: Unlike supervised learning algorithms, unsupervised learning algorithms are used when we do not 
have a specific prediction target or outcome. This type of machine learning algorithm is frequently used in clustering and 
recommendation systems. As an example, you can use unsupervised learning algorithms to cluster your customer base into different 
subgroups or segments, based on their behaviors. In this case, we do not have a specific target or outcome that we want to predict. 
We are just grouping similar customers together into different segments.

Reinforcement learning algorithms: These algorithms are used when we want the model to continuously learn and train itself without 
prior knowledge or experience. In the case of reinforcement learning, the model learns how to make predictions after lots of trials 
and errors. One example of the application of reinforcement learning in marketing is when there are multiple marketing strategies 
you'd like to test and choose the one that works the best. In this case, you can run a reinforcement learning algorithm, where it 
randomly picks one strategy at a time and gets rewarded when a positive outcome occurs. After multiple iterations of trials and 
errors, the reinforcement learning model will have learned to choose the best marketing strategy, based on the total rewards each 
marketing strategies have earned

"""