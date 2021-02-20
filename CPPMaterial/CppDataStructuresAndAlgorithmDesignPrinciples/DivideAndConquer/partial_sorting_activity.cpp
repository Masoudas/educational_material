/**
* In this exercise, we're going to expand the notion a bit, and in fact, ask for a begin and end for the range
* that we want sorted. This is crucially like the implementation defined by the std::partial_sort, wit the diff
* being that we ask for a mid_begin and mid_end rather than just a mid.
* 
* So I made two mistakes when implementing this algorithm:
* 1- I tend to always forget that end does not point to the last element of an iterable, but rather one after
* that! I'm sure I'll keep this in mind in the future!
* 2- The other mistake was to use the partition method of C++ to the pivot step! I rectified it by brining in
* my implementation of partition from Sedgewick. If I wanted to use partition, I need to implement a two step
* approach. Step one would be to partition with 'less than'. Step two would be to implement with == from the
* second part of the partition, in which case we go over some elements twice!
* 
*/
#include <algorithm>
#include <vector>
#include <iostream>

template<typename _Itr>
void print_vector(_Itr mid_begin, _Itr mid_end)
{
	for (; mid_begin < mid_end; ++mid_begin)
		std::cout << *mid_begin << " ";
	std::cout << std::endl;
}

template<typename _Itr>
_Itr partition(_Itr begin, _Itr end) {
	_Itr i = begin; _Itr j = end;
	auto v = *begin;

	while (true)
	{
		while (*++i < v) if (i == begin) break; // No equal comparison. If equal, we break.
		while (v < *--j) if (j == end) break; // No equal comparison. If equal, we break.

		if (i >= j) break;

		std::swap(*i, *j);
	}

	std::swap(*begin, *j);

	return j;
}

template<typename _Itr>
void partial_sort(_Itr begin, _Itr mid_begin, _Itr mid_end, _Itr end) {
	if (begin >= end) return;

	_Itr item = partition(begin, end);
	print_vector(begin, end);
	if (item < mid_begin) {
		partial_sort(++item, mid_begin, mid_end, end);
	}
	else if (item >= mid_begin && item < mid_end) {
		partial_sort(begin, mid_begin, mid_end, item);
		partial_sort(item + 1, mid_begin, mid_end, end);
	}
	else {
		partial_sort(begin, mid_begin, mid_end, item);
	}
}


//int main() {
//	std::vector<int> v1{ 5, 7, 4, 6, 3, 2, 1};
//	
//	auto mid_begin1 = v1.begin() + 2; auto mid_end1 = v1.begin() + 5;
//	partial_sort(v1.begin(), mid_begin1, mid_end1, v1.end());
//	// sorted range is [ .. 2, 3, 4, 5, .. ]
//	print_vector(mid_begin1, mid_end1);
//}