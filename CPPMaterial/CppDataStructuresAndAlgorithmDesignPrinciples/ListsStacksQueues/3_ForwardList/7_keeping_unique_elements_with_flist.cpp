/**
* The unique function compares an element with its next element and if they're equal, removes the duplicate.
* Note that:
* 
* 1- When it removes the next one, it does not increment the index, but rather compares the same index with
*	the one. Hence, 1 1 1 2 becomes 1 2.
* 2- In this scheme, traversing the array would be linear, and the first instance of each repetition is kept.
* 
* Therefore, if a repetitive element is scattered around in a list, we need to first sort it, and then remove
* the duplicates. Note that with this scheme, the first element of the list is always kept, hence the list
* will never be empty after unique.
* 
* Note finally that this method uses the == operator of the type, or a function pointer supplied by the user.
* 
*/

#include <forward_list>
#include <algorithm>
#include <sstream>
#include <iostream>

using std::forward_list;

void removing_consecutive_duplicates() {
	forward_list<int> l{ 1, 1, 1, 2, 3, 1, 4, 1, 1, 5 };

	l.unique([](const int x, const int y)->auto{ return x == y; });

	std::ostringstream o;
	o << "Notice that non-consecutive duplicate ones are not removed:\n";
	std::for_each(l.cbegin(), l.cend(), [&](int v)->void {o << v << "\t"; });
	std::cout << o.str();
}

void removing_all_duplicates() {
	forward_list<int> l{ 1, 1, 1, 2, 3, 1, 4, 1, 1, 5 };
	l.sort(std::less<int>{});
	l.unique([](const int x, const int y)->auto{ return x == y; });

	std::ostringstream o;
	o << "\nNow, all duplicates are removed:\n";
	std::for_each(l.cbegin(), l.cend(), [&](int v)->void {o << v << "\t"; });
	std::cout << o.str();
}

void removing_close_duplicates() {
	forward_list<float> l{ 1.1f, 1.11f, 1.09f, 2.5f, 3.1f, 4.0f, 5.8f };
	l.unique([](const float x, const float y)->bool{ return (x - y) < 0.1f && (x - y) > -0.1f; });

	std::ostringstream o;
	o << "\nRemoving close duplicates:\n";
	std::for_each(l.cbegin(), l.cend(), [&](int v)->void {o << v << "\t"; });
	std::cout << o.str();
}


//int main() {
//	removing_consecutive_duplicates();
//	removing_all_duplicates();
//	removing_close_duplicates();
//}
