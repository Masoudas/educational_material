/*
* Partitioning is the pickle of the algorithm, and the implementation in Sedgewick is 
* very beautiful. I wish I had come up with it.
* 
* The idea is that is that:
* 1-	The entry j is in its final position, for some j.
* 2-	No entry from lo to j-1 is greater than the j-th element.
* 3-	No entry from j+1 to hi is less than the j-th element. 
* 
* Assuming the above condition, we can prove by induction that the array is sorted. That is assuming
* the left array is sorted as such, and the right as well, then their combination with the middle array
* is sorted.
* 
* The idea is as follows: We start from i = lo + 1 and index j = hi + 1. From bottom we go so far
* as we meet an element that is greater than i = 0 and then stop. We do the same from the top,
* stopping at element below i = lo. Now we have two elements we can swap. We continue
* like this until i and j cross path, in which case everything from j+1 is greater than i = 0.
* Now we just need to exchange lo with j. 
* 
* Note that this scheme is not dependent on the choice of the pivot. In fact, we can randomize by
* either choosing randomly or shuffling.
* 
* Naturally, if j becoms equal to the low index or i is equal to high element, we then have to stop.
* We could actually add this condition to the while loop for j to stop sooner.
* 
* It's very important to check for less than equal and greater than equal in both cases of 
* comparison, otherwise with some typical cases, we might run into quadratic times. Even though
* this causes us to do some unnecessary exchanges.
* Note: It's baffling though. Say all elements of the array are equal. We'd exchange everytime!
* So at least for the trivial case, it seems to increase running time.
* 
* My God, just imagine how brilliant, yet simple this algorithm is.
*/
#include <iostream>
using namespace std;

template <typename T>
void quick_sort_exchange(T* t, int i, int j) {
	T temp = t[i];
	t[i] = t[j];
	t[j] = temp;
}

template <typename T>
int quick_sort_partition(T* t, int lo, int hi) {
	int i = lo;	int j = hi + 1;	// We could have started from hi, but it would have been complicated.
	T v = t[lo];

	while (true)
	{
		while (t[++i] < v) if (i == hi) break;	// The importance of if is clear, which avoids overflow.
		while (v < t[--j]) if (j == lo) break;	// Se exercise 17 for how to reducde the ifs.

		if (i >= j) break;
		quick_sort_exchange(t, i, j);
	}

	quick_sort_exchange(t, lo, j);
	return j;
}

//int main() {
//	// Testing. Should print [1 2 3 4] for this vector. 
//	int arr[] = { 3, 4, 2, 1 };
//	quick_sort_partition(arr, 0, 3);
//
//	for (auto val : arr) {
//		cout << val << "\t";
//	}
//	cout << endl;
//}