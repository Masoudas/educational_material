/**
* The following is inpired by the difference between std::adjacent_difference and std::partial_sum in algorithm
* header of C++.
* 
* A common problem is to write for loops depending on the previous value. Assume that the first item remains the
* same. So we can implement the loop in such a way that the next value is calculated using the original value,
* or using the newly calculated sum. For example if I have the vector {1, 1, 1, 1}, I can have:
* {1, 2, 2, 2} ---> Not dependent on newly calculated value.
* {1, 2, 3, 4} ---> Depends on newly calculated value (commulative sum).
* 
* Now consider the implementations below. non_cummlative_recursive_loop actually moves the current element into
* the prev, making it independent of what is put there after loop (very interesting, no?!). Whereas cumsum is 
* implemented to keep the current result. See, two very different views of how the loop is implemented.
*/
#include <algorithm>

template<typename T, typename Func>
void non_cummlative_recursive_loop(T* start, T* end, const Func& f) {
	T prev = *start;
	while (++start != end) {
		T curr = *start;	// Get a copy of current value.

		*start = f(prev, curr);

		prev = std::move(curr);	//
	}

}

template<typename T, typename Func>
void cummlative_recursive_loop(T* start, T* end, const Func& f) {

	T result = *start;
	for (;;) {
		*start = result;
		++start;
		if (start == end) {
			break;
		}

		result = f(result, start);
	}
}
