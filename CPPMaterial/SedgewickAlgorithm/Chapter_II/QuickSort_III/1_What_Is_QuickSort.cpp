/**
* Quick sort is in a way a complement of merge sort. In merge sort, we merge two already sorted
* arrays with each other. In quick sort we do the the reverse. We create two arrays, each of which
* are less than and greater than our pivots, and then, we repeat the same step for those two. Note
* that in merge sort, we partition our array in half, whereas in quick sort, the pivot element determines
* the size of each subarray.
* 
* The crux of the quicksort is the partitioning part, which is discussed next.
* 
* On average, this algorithm requires NlogN sorts.
* 
* To avoid worse case scenarios, we randomly shuffle our data.
* 
* It's evident that quick-sort uses at most ~N^2/2 comparisons (N, N-1, ..., 1), however 
* shuffling ensures that the worst case (where the smallest item in every row is chosen as
* pivot every single time) is not likely to happen.
* 
*/