/**
* As opposed to array or vector iterators, where we can easily access any element that we desire,
* with list iterators we can't do no such action. In other words, the iterator of vector and array
* is random access, but not that of forward list. We can't simply add an integer to the iterator. Note also
* that decrement is not possible for the iterators as well, only increment.
* 
* We can also use prev and next methods of the iterator to get a new iterator poiniting to the next
* element. Note however that with forward_list, we can't use prev, and if we do so, we get a
* compile-time error.
* 
*/

#include <forward_list>
#include <algorithm>
#include <iostream>

using std::forward_list;

void using_iterators_of_forward_list() {
	forward_list<int> l{ 1, 2, 3, 4, 5 };

	forward_list<int>::iterator itr = l.begin();

	// itr + 2 This is not possible!
	// (itr++)++; Oh no! Don't do this. This will point to an arbitrary memory location.

	std::advance(itr, 2);	// Advance the iterator two positions, arriving on third element.
	auto itr1 = l.begin();
	auto fourth_elem_ptr = std::next(itr1, 3);

	std::cout << "The third element is: " << *itr << " and the fourth element is: " << *fourth_elem_ptr;

	// std::prev(itr1, -3); Error! Can't go back. Need to start from the top.

}

//int main() {
//	using_iterators_of_forward_list();
//}