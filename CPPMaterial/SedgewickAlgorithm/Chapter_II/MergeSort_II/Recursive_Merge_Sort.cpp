/*
* 
* In this example, we try to implement the recursive merge sort in C++.
* We implement the class using a template, assuming that this template implements a less than operation.
* 
* Again, we ask for the size of template, to be able to copy the memory.
* 
* I encourage you to pay attention to how the static class is defined, and how the static parameter is 
* initialized outside the class! That being said, a more inteligent design would be to use aux as a
* local parameter, and to also exchange places to avoid the need for copy.
* 
*/
#include <memory>
#include <iostream>
#include <cmath>

template <typename T, int SIZE_T>
class MergeSort {
public:
	static void merge_sort(T* arr, int size) {
		size = size;
		aux = new T[size];

		sort(arr, 0, size - 1);
	}

private:
	static void merge(T* a, int lo, int mid, int hi) {
		int i = lo;
		int j = mid + 1;

		std::memcpy(aux + lo, a + lo, SIZE_T * (hi - lo + 1));

		for (int k = lo; k <= hi; k++)
		{
			if (j > hi) a[k] = aux[i++];
			else if (i > mid) a[k] = aux[j++];
			else if (aux[i] <= aux[j]) a[k] = aux[i++];
			else a[k] = aux[j++];
		}
	}

	static void sort(T* arr, int lo, int hi) {
		if (lo == hi) return;

		int mid = lo + std::floor((hi - lo) / 2);

		sort(arr, lo, mid);
		sort(arr, mid + 1, hi);

		merge(arr, lo, mid, hi);

	} 

private:
	static T* aux;

};

template<typename T, int SIZE_T>
T* MergeSort<T, SIZE_T>::aux = nullptr;


//int main() {
//	int arr[] = { 6, 1, 4, 5, 2, 3, 7, 12, 13, 10, 8, 9 };
//
//	MergeSort<int, 4>::merge_sort(arr, sizeof(arr) / sizeof(arr[0]));
//
//	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
//	{
//		std::cout << arr[i] << std::endl;
//	}
//
//	std::cin.get();
//}