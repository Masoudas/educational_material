/**
* We implement the heap sort as shown below. Note that we ask the user to provide a compare method, and if
* they don't, we use the std::less/
*/
#include <iostream>
using namespace std;
template<typename T, typename LESS = std::less<T>>
struct heap_sort {
private:
	const LESS is_less_than{};	// Instantiating comapre class.
	using _Tptr = T*;

public:
	void sort(_Tptr begin, _Tptr end) {
		int N = end - begin - 1;

		for (int i = N / 2; i >= 0; --i) {
			sink(begin, i, N);
		}

		while(N > 0){
			swap(begin[N--], begin[0]);
			sink(begin, 0, N);
		}
	}

private:
	void sink(_Tptr begin, int k, int N) {
		while (2 * k + 1 <= N)
		{
			int i = k * 2 + 1;
			if (i + 1 <= N && is_less_than(begin[i], begin[i + 1])) i++;
			if (!is_less_than(begin[k], begin[i])) break;
			swap(begin[k], begin[i]);
			k = i;
		}
	}
};


//int main() {
//	int arr[] = { 3, 1, 2 };
//
//	heap_sort<int> sorter{};
//	sorter.sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	for (auto val : arr) {
//		cout << val << '\t';
//	}
//}