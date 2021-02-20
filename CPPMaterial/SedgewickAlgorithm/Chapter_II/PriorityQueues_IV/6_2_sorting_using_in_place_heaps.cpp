/**
* So now, assume that we have constructed the heap. How do we sort the array?
* 
* Recall that how we deleted a maximum in the priority queue. Now, all we have to do
* is to delete the maximum, and then exchange the last element of the array with the first,
* and then sink that first element to get our new heap. This way, deletion can be done in place.
* 
* As we'll demonstrate with the implementation next, this algorithm results in a very compact 
* sorting algorithm. Therefore, the algorithm is suitable for embedded systems. However, the algorithm
* has so many near miss caches that modern systems don't implement it at all.
* 
* Question: How many exchanges are required in the deletion substitution process?
* We know that we require N/2(logN) for the leaf nodes. This is because half as many nodes are there, and then
* a sink requires at most logN to get there. Then we require N/4(logN-1) for the next level. Arguing in the same
* line as the construction of heap, we see that we require no more than NlogN exchanges and no more than twice
* that many comparisons.
* 
* Question: What is the total number of compares of heap sort? Adding construction of heap to the previous
* part, we conclude 2N + 2NlogN.
*/