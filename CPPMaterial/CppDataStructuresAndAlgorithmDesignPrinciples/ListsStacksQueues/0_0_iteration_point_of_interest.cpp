/**
* As we may have noticed, stl provides several facilities for us for iteration over various containers.
* These are for example:
* 
* 1- rbegin() and rend(): For a vector and for an initializer list, returns an iterator starting
*	from last to first element, using INCREMENT operator. For completeness, returns the rbegin or crbegin
*	as well as a wrapper function (Notice how the implementation uses decltype for return type, extracting 
*	the iterator type for return type). Hence, it works for a container iff it has a reverse iterator.
* 2- next, advance, prev: Instead of having to write the for loop to increment an iterator by hand, provides
*	facilities to advance an iterator, using ++ and -- operators. Note that the container must provide 
*	required -- or ++ operator (for example, forward_list does not have --).
* 
*/
#include <array>
#include <initializer_list>
#include <algorithm>

using namespace std;

void getting_reverse_iterator() {
	std::initializer_list<int> l{ 1, 2, 3, 4 };
	std::for_each(std::crbegin(l), std::crend(l), [](int v) {});

	int arr[]{ 1, 2, 3, 4 };
	std::for_each(std::rbegin(arr), std::rend(arr), [](int v) {});

	array<int, 5> std_arr{ 1, 2, 3, 4, 5 };
	std::for_each(std::rbegin(std_arr), std::rend(std_arr), [](int v) {});	// Fine, wrapper around
																			// array::rbegin().
}

void changing_iterator_location() {
	array<int, 5> std_arr{ 1, 2, 3, 4, 5 };

	auto third_elem = std::next(std_arr.begin(), 2);	// Take it to third element;
	auto first_elem = std::next(std_arr.begin(), -2);	// First element.
	std::advance(first_elem, 2);	// Must be given an lvalue iterator. Note that it has no return type!
									// First element is now on the third element.
}