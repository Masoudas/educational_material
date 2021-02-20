/**
* is_<algo> algorithms return a boolean, saying whether the collection satisfies the algorithm, like
* is_sorted, is_heap, is_partitioned
* 
* is_*_until returns an iterator where the predicate doesn't hold. For example, for a sorted collection,
* is_sorted_until returns the end of that collection. is_sorted_until checks if in increasing order, hence,
* we need reverse iterator for decreasing order, or simply, we can supply a compare method!
*/

#include <algorithm>
#include <array>
#include <vector>
#include <iostream>

void _is_until_examples() {
	constexpr std::array<int, 4> vec{ 1, 3, 2, 4 };

	// Check if sorted till second element. Returns third element iterator of course.
	constexpr std::array<int, 4>::const_iterator last = std::is_sorted_until(vec.cbegin(), vec.cbegin() + 2);	
											// As always, a comparison with last = end() tells us that last must
											// be the element after which we want to check!
	if constexpr (last == vec.begin() + 2) {
		// We're happy!
	}

	std::vector<int> vec1{ 4, 2, 1, 3 };
	auto rend = std::crend(vec1);	// Element two as reverse.
	auto rbegin = std::crbegin(vec1) + 2;	// Begin of list as reverse, and actually one before it!
	auto rlast = std::is_sorted_until(rbegin, rend);	// Checks if increasing from second element to first.
													// Returns one before begin!

	std::cout << "Array decreasing sorted portion is: ";
	// We need to reverse iterate from last1. Note that last++ actually decreases the index.
	// It's very interesting to note that for reverse comparison, we don't say rlast <= rbegin!!!
	// It's actually manufactured in a way so that pointers that are left of begin are considered less than
	// those of right!!! God almighty it's cool!
	for (--rlast; rlast >= rbegin; --rlast) {
		std::cout << *rlast << "\t";
	}

	// Avoiding the complication by supplying a predicate.
	auto last_reverse_sorted = std::is_sorted_until(
		vec.begin(), vec.begin() + 2, [](const int& v, const int& w) { return w > v; });

}

//int main() {
//	_is_until_examples();
//}