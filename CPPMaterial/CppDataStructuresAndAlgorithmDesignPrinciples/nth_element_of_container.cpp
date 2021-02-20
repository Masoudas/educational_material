/**
* It's typical to be asked to calculate the nth largest element of an array. In what follows, we shall discuss how
* to do so in (approximately) linear time.
* 
* A couple of other solutions before discussing the main solution:
* 1- Using quick-sort for finding the nth element: This is potentially good, and assuming a randomness is
* introduced in the beginning, the performance is acceptable. However, it definitely exceeds linear time.
* 
* 2- Using a pq: Heapifying an array takes O(n) time. Then popping each element takes O(log(n)) time. Hence
* finding the middle element (assuming we use min and max depending on whether the element is close to the 
* beginning or end) takes O(nlog(n)), which is not pleasing, and is equivalent to a total sort.
* 
* Now, we go about the solution using divide and conquer. The idea is as follows:
* 1-	Divide the array in subsets of five, and sort each one (last one may contain less elements).
* 2-	Find the median of each subarray.
* 3-	Find the median of the medians.
* 4-	Apply a partitioning of the array, and place the median of medians where it belongs.
* 5-	If the placed element is the one we seek, return, otherwise either go to LHS or RHS arrays formed from the
*		above operation and repeat until reaching the nth element.
* 
* Ok! We see that this algorithm pretty much resembles the quick-sort version we discussed above. However, ordering
* of the small elements we discussed above, together with using the median ensures that this algorithm is 
* approximately linear time.
* 
* Also of interest, note that we said above that we partition the vector into elements of five. Why five? This 
* apparently has been deduced by impirical studies, and gets us closer to linear time.
* 
* Here's a thought. What if we can't compute a median for the data? Like for example for strings, or a type that
* has a particular order? The beauty of this algorithm is that it does not depend on a type having numerical 
* median. Hence for example after sorting the five elements, we only need to return the center element. That's 
* cool.
*/