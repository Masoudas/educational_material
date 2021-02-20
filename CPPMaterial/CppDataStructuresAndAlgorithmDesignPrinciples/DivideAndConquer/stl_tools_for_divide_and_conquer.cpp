/**
* As we already know, stl provides several methods in the algorithm header that use divide and conquer. These
* include the following methods:
* -	binary_search
* - search: Searches for the first occurrence of the sequence of elements [s_first, s_last) in the range 
*	[first, last). Don't also forget find_if.
* - upper_bound: Returns an iterator to the first element in the array that is greater than the given value.
* - lower_bound: ...  lower than ...
* - partition: ...
* - partition_copy: ...
* - is_partitioned: ...
* - stable_partition: ...
* - sort, stable_sort, partial_sort, etc: ...
* - merge: For merging two containers, as done in the merge sort method.
* - nth_element: The nth element of an array.
* - accumulate: Reduces the elements of an array into one element. Can be used to sum an array. Obsolete, and we
*				should use reduce.
* - transform: Applies a transform function to each element of the container.
* - reduce: Takes a reduction operator, applies it to the container, and returns the result.
*/
#include <algorithm>
#include <iostream>

void search_method() {
	const char* str = "This is my string in which I want to search";
	const char* search = "I want to";

	// Recall that strlen returns the length minus the terminating null char.
	auto found = std::search(
		str, str + strlen(str) + 1, search, search + strlen(search));

	std::cout << "Printing from the found location to the end of the string:\n";
	if (found != str + strlen(str))
		while (found != (str + strlen(str) + 1)) std::cout << *found++;
}

//int main() {
//	search_method();
//}