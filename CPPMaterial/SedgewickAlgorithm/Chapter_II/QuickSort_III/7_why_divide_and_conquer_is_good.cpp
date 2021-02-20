/**
* Here's an important point that I overlooked. Divide and conquer is good, because breaking down
* problems in half is good (which is why marriage is good for example).
* 
* So image I want to sort an array. If I find the smallest element, then the second smallest and so forth,
* that will take n^2 comparisons. We can't go any worse than that.
* 
* However, imagine we go for a divide and conquer scenario. Our best hope is to divide the array in two
* separate problems, meaning, find the middle element. Why? Because imagine now that we have two subarrays of N-1/2
* Then we have two of these. Yes, it's true that we still need (N-1)/2 - 1 comparison for each of these subarrays
* to sort them. However, if we're lucky everytime and the problem is broken down from the middle, the total length of
* the tree formed by this will be logn. Hence, because at every level of that tree we need N-1 comparisons (say
* (N-1)/2 - 1 + (N-1)/2 - 1, which is approximately N-1), then the total number of comparisons reduce to NlogN, as opposed
* to N^2.
* 
* In conclusion, breaking down the problem in half, or divide and conquer always helps.
* 
* So what if I broke it in thirds? We know that mathematically, we can't do any better than NlogN on average. Hence, we'd 
* reach the same near complexity. The reason why we don't see any improvements is because the probability of falling
* on every third is much lower than falling on every second.
*/