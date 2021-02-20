/**
* Now it's time to implement a full quick sort. 
* 
* As an exercise in using templates, we're going to pass a reference to array rather than a pointer.
* Note however that using pointers is I think a better idea, as the quick-sort of algorithm
* module itself uses pointers (which we supply using iterators for example).
* 
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

template <typename T, int N>
class quick_sort {
public:
	static void sort(T(&t)[N]) {
		shuffle(t);
		sort_quick(t, 0, N - 1);
	}

private:
	/**
	* To shuffle, we generate a random number between 0 and N - 1, and exchange that element
	* with the last element. We do it N times. This strategy was suggested by Sedgewick.
	* The advantage is that we generate a random number only once.
	*/
	static void shuffle(T(&t)[N]) {
		srand(static_cast<unsigned>(time(0)));	// Randomize generation of random numbers between calls,
												// using time.
		for (int i = 0; i < N; i++)
		{
			int index = rand() % N;	// Random number between 0 and N-1.
			exchange(t, N - 1, index);
		}
	}

	static void sort_quick(T(&t)[N], int lo, int hi) {
		if (hi <= lo) return;

		int j = partition(t, lo, hi);
		sort_quick(t, lo, j - 1);
		sort_quick(t, j + 1, hi);
	}

	static int partition(T(&t)[N], int lo, int hi) {
		int i = lo; int j = hi + 1;
		T v = t[lo];

		while (true)
		{
			while (t[++i] < v) if (i == hi) break; // No equal comparison. If equal, we break.
			while (v < t[--j]) if (j == lo) break; // No equal comparison. If equal, we break.

			if (i >= j) break;

			exchange(t, i, j);
		}

		exchange(t, lo, j);

		return j;
	}

	static void exchange(T(&t)[N], int i, int j) {
		T temp = t[i];
		t[i] = t[j];
		t[j] = temp;
	}
};


//int main() {
//	int arr[] = { 4, 2, 1, 6, 3, 7 };
//
//	quick_sort<int, sizeof(arr)/sizeof(arr[0])>::sort(arr);
//
//	for (auto val : arr) {
//		cout << val << "\t";
//	}
//	cout << endl;
//}