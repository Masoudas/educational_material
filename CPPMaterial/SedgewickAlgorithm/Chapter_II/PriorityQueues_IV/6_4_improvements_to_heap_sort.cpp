/**
* Proposed by Floyd in 1964, it's useful for when the cost of comparison is very high, like for example 
* with strings.
* 
* As is evident, during the removal of maximum for the sortdown operation, the elements that are put
* on the top would mostly sink to the bottom. This is because bottom elements tend to be smaller.
* 
* So Floyed proposed that instead of performing an actual sink, we just promote the larger of two children.
* This way, we intuitively expect the element to continue sinking. But perhaps at some point
* it will sink below a heap it should have. For example if the element is 4 and the nodes are 1 and 2,
* then 2 is changed with 4. So now 4 is below 2. So how do we fix it? We just need to swim from this last
* node and go back up. If we do so, then those smaller nodes that are on top will be replaced by their children.
* 
* The only thing that we need to take care of here is to remember the index of the last node.
*/


#include <iostream>
using namespace std;
template<typename T, typename LESS = std::less<T>>
struct heap_sort {
private:
	const LESS is_less_than{};	// Instantiating comapre class.
	using _Tptr = T*;

public:
	void sort(_Tptr begin, _Tptr end) noexcept {
		int N = end - begin - 1;

		for (int i = N / 2; i >= 0; --i) {
			sink(begin, i, N);
		}
		
		while (N > 0) {
			swap(begin[N--], begin[0]);
			int leaf = promote_child(begin, 0, N);
			swim(begin, leaf);
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

	int promote_child(_Tptr begin, int k, int N) noexcept {
		while (true)
		{
			if (2 * k + 1 > N) return k;

			int i = k * 2 + 1;
			if (i + 1 <= N && is_less_than(begin[i], begin[i + 1])) i++;
			swap(begin[k], begin[i]);
			k = i;
		}
	}

	void swim(_Tptr begin, int k) noexcept {
		while (k > 0 && is_less_than(begin[(k-1) / 2], begin[k])) {
			swap(begin[(k-1)/2], begin[k]);
			k = (k-1) / 2;
		}
	}
};

//int main() {
//	int arr[] = { 6, 3, 2, 1, 5, 4, 8, 7};
//
//	heap_sort<int> sorter{};
//	sorter.sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	for (auto val : arr) {
//		cout << val << '\t';
//	}
//}