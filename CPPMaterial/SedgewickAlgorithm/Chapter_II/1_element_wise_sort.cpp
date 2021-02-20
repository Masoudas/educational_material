/**
* As an exercise, imagine we want to sort an array of three elements. How do we go about this using
* minimal implementation?
* 
* 1- We compare 0 and 1. Hence, we have a partial sorting,
* 2- We compare 1 and 2. Why? To keep relative order of 0 and 1. Otherwise, last step is ruined.
* 3- We have not compared 0 and 2 yet. (especially if 2 is replaced with one). So we need now to compare 0 and 1
* to determine their relative situation.
*/
template <typename T>
void sort_three_elements(T* begin) {
	if (begin[0] > begin[1]) swap_arr_elements(begin, begin + 1);
	if (begin[1] > begin[2]) swap_arr_elements(begin + 1, begin + 2);
	if (begin[0] > begin[1]) swap_arr_elements(begin, begin + 1);
}

/**
* Sort for four elements: We can sort the first three elements. Then, compare fourth with the middle element
* and then with either side. This optimizes in terms of comparisons, as we use only 5. But perhaps the
* number of swaps increases compare to the case if we start from the last item and come recursively back
* (compare 3 to 2, then 2 to 1, then 1 to 0).
*/
template <typename T>
void sort_four_elements(T* begin) {
	sort_three_elements(begin);

	if (begin[1] > begin[3]) {
		swap(begin[2], begin[3]);
		swap(begin[1], begin[2]);

		if (begin[0] > begin[1]) swap(begin[0], begin[1]);
	}
	else {
		if (begin[2] > begin[3]) swap(begin[2], begin[3]);
	}

}
