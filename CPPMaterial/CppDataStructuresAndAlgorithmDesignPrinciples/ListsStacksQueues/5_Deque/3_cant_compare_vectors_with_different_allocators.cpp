/**
* As we may already know, an allocator is a template parameter of a deque. Therefore, we can't compare
* two deques (or vectors, etc for that matter) for equality directly. Instead what we can do it to use 
* iterators, and compare them using iterators.
*/

#include <deque>
#include <vector>
#include <algorithm>

// Read the following example!
//void comparing_two_deques() {
	//using std::deque; 

	//struct Alloc {};
	//deque<int> d1{ 1, 2, 3 };
	//deque<int, Alloc> d2{ 1, 2, 3 };

	// if (d1 == d2) Wrong! Unequal types.

	//std::equal(d1.cbegin(), d1.cend(), d2.cbegin());	// Compares regardless of allocators, because the template
														// is not part of iterator
//}