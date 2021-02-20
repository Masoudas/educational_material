/**
* So, we've discussed already how to ge the median of streaming data using two priority queues. Here, we shall 
* discuss how to get the median of already existing arrays.
* 
* The idea is simple, if we use nth_sort algorithm for the middle element, then we can find the median. The only
* point that remains is to recall that for even number of elements, we need to procure the middle two elements.
* Here's an implementation that uses the C++ nth_element algorithm. Note that in this scheme, the order of the 
* list changes.
* 
* Note that the assumption here is that the type has a random iterator. Consequently, the median of a list can't
* be found as such.
* 
* Note that the above algorithm is O(n), where as that of the streaming median is (essentially) O(1), or O(log(n))
* for the case where we insert new elements.
* 
* A note on the return type: Naturally, the return type has to be double, otherwise we could use auto, or if we're
* sure that each iterator has something called value_type as an alias, we could define that as template. The point
* is that we can't use auto and then say decltype(_RndItr::value_type). A type that is declared has to be calculated,
* 
*/
#include <algorithm>
#include <vector>
#include <iostream>

template<typename _RndItr>
auto median(_RndItr begin, _RndItr end) {	// Naturlich, we want the return type to be double for even num elems.
	size_t N = std::distance(begin, end);	// It had never occured to me that we can determine the distance of 
											// two iterators as well.

	size_t middle = N / 2;	// This would point to middle or middle plus one
	auto n_th = std::next(begin, middle);
	std::nth_element(begin, n_th, end);

	if (!(N % 2)) { // If there are even number of elements
		auto n_1_th = std::next(begin, middle - 1);
		std::nth_element(begin, n_1_th, end);

		return (*n_1_th + *n_th) / 2;
	}

	return *n_th;
}

//int main() {
//	std::vector<double> v1{ 5.0, 7.0, 4.0, 6.0, 3.0, 2.0, 1.0, 8.0};
//	
//
//	std::cout << "Median is: " << median(v1.begin(), v1.end());
//}