/**
* The idea for implementing the quick-sort without recursion is that we need an auxiliary memory
* to keep track of the pivots. That way, we can move on them and once an interval is finished,
* we move up after the next pivot. The additional space needs at most log(N) locations at a time.
*
*/
#include <stack>
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
class loop_quick_sort {
public:
	static void sort(T* start, T* end) {
		int N = end - start;

		shuffle(start, N);

		stack<int> pivots{};
		int lo = 0;
		int j = N - 1;
		int hi = N - 1;
		while (lo < N - 1)
		{
			j = partition(start, lo, hi);
			pivots.push(j);

			if (j == lo) {
				lo = pivots.top() + 1;
				pivots.pop();
				if (pivots.size() == 0) {
					hi = N - 1;
				}
				else {
					hi = pivots.top() - 1;
				}
			}
			else {
				hi = pivots.top() - 1;
			}

		}

	}

private:
	static void shuffle(T *start, int N) {
		srand(static_cast<unsigned>(time(0)));	// Randomize generation of random numbers between calls,
												// using time.
		for (int i = 0; i < N; i++)
		{
			int index = rand() % N;	// Random number between 0 and N-1.
			exchange(start, N - 1, index);
		}
	}

	static int partition(T *start, int lo, int hi) {
		if (lo >= hi) return lo;

		int i = lo; int j = hi + 1;
		T v = start[lo];

		while (true)
		{
			while (start[++i] < v) if (i == hi) break;
			while (v < start[--j]) if (j == lo) break;

			if (i >= j) break;

			exchange(start, i, j);
		}

		exchange(start, lo, j);

		return j;
	}

	static void exchange(T *begin, int i, int j) {
		T temp = begin[i];
		begin[i] = begin[j];
		begin[j] = temp;
	}
};

//int main() {
//	int arr[] = { 4, 5, 2, 1, 3, 6, 7};
//
//	loop_quick_sort<int>::sort(arr, arr+7);
//
//	for (auto val : arr) {
//		cout << val << "\t";
//	}
//	cout << endl;
//}

