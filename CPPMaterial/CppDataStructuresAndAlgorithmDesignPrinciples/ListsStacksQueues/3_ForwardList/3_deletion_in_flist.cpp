/**
* We have two methods for removing objects from a list:
* 
* 1- pop_front(): Removes the element at the front of the list.
* 2- erase_after(begin, end=optional): By providing an iterator, removes the first element after, to the 
*	end element exclusive (which does make sense, because the function only accepts const iters, so you expect the
*   corresponding elements to remain after erasing).
* 
* Here's a thought from me: His highness, the great Bjarne says that insertion in the list is O(n), because 
* it takes a n iterations to find the node. This is indeed true. Note that as opposed to a vector, the iterator
* of a forward list does not overload addition with arbitrary integer. Why? Because reaching the pointer
* to that element is not as trivial as addition a value to a pointer. 
*/

#include <forward_list>
#include <algorithm>
#include <iostream>

void popping_front() {
	using list = std::forward_list<int>;

	list l1{ 1, 2, 3, 4, 5, 6 };
	l1.pop_front();	// The only legitimate way to pop the front element.
}

void remove_using_erase_after() {
	using list = std::forward_list<int>;

	list l1{ 1, 2, 3, 4, 5, 6 };
	l1.erase_after(l1.begin());	// Remove the first element after first, now it's {1, 3, 4, 5, 6}.

	list::iterator third_elem = l1.begin();
	for (int i = 1; i <= 2; i++) {
		third_elem++;
	}
	// auto third_elem = std::next(l1.begin(), 2); Same operation, using stl

	l1.erase_after(l1.cbegin(), third_elem);

	std::for_each(l1.cbegin(), l1.cend(), [](int n)->void {std::cout << n << "\t"; });
}

//int main() {
//	remove_using_erase_after();
//}
