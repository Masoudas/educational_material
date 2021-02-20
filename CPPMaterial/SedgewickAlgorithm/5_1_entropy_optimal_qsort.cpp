/**
* For the fun of it, here we try to implement a version of qsort that uses the Dutch National Flag
* solution.
* 
* Note the use of swap for changing elements.
*/
#include <tuple>
#include <iostream>
using namespace std;

template <typename T>
class entropy_optimal_qsort {
public:
	static void sort(T* begin, T* end) noexcept {
		int N = end - begin;

		_qsort(begin, 0, N-1);

	}
private:
	static void _qsort(T* begin, int lo, int hi) noexcept {
		if (lo >= hi) return;	// This condition is crucial, as we could have lo = gt + 1 > hi

		int lt;
		int gt;
		std::tie(lt, gt) = _entropy_optimal_partition(begin, lo, hi);

		_qsort(begin, lo, lt - 1);
		_qsort(begin, gt + 1, hi);
	}

	static tuple<int, int> _entropy_optimal_partition(T* begin, int lo, int hi) noexcept {
		int i = lo + 1; int lt = lo; int gt = hi;
		T v = *(begin + lo);

		while (i <= gt){	// Equality case is crucial for if gt does not move!
			T elem = *(begin + i);
			if (elem < v) swap(begin + i++, begin + lt++);
			else if (elem > v) swap(begin + i, begin + gt--);
			else i++;
		}

		return make_tuple( lt, gt );
	}

	
	static void swap(T* t1, T* t2) {
		T temp = move(*t1);
		*t1 = move(*t2);
		*t2 = move(temp);
	}



};

//int main() {
//	int arr[] = { 4, 5, 1, 1, 1, 6, 7};
//
//	entropy_optimal_qsort<int>::sort(arr, arr+7);
//
//	for (auto val : arr) {
//		cout << val << "\t";
//	}
//	cout << endl;
//}