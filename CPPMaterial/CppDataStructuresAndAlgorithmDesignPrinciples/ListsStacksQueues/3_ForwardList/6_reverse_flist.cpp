/**
* As we may recall, to reverse a list, we start from the first and last element, and we put the first
* element at the tail end of the last, avoiding a loop, by putting the last element by putting the
* last element before the first element.
* 
* The reverse function of a list takes care of this situation for us, making the reversing time of order
* O(n).
* 
* Once again, note that because we can't iterate from the back of the list to the front, we can't 
* actually use std::rbegin or stl::end.
*/
#include <forward_list>
#include <algorithm>
#include <sstream>
#include <iostream>

using std::forward_list;

void reversing_a_forward_list() {
	forward_list<int> l{ 1, 2, 3, 4, 5 };

	l.reverse();

	std::ostringstream o;
	o << "After reversing: ";
	std::for_each(l.cbegin(), l.cend(), [&](int v)->void {o << v << "\t"; });
	std::cout << o.str();
}

//int main() {
//	reversing_a_forward_list();
//}