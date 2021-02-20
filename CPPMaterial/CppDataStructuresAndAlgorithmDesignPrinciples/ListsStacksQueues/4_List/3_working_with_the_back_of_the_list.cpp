/**
* As opposed to forward_lists, lists allow us to work with their back too. These methods include 
* emplace_back, pop_back.
*/

#include <list>
#include <algorithm>
#include <iostream>

using std::list;

std::ostream& operator<<(std::ostream& o, const list<int>& l) {
	std::for_each(l.begin(), l.end(), [&](int v) { o << v << '\t'; });

	return o;
}

void working_with_back_of_list() {
	list<int> l{ 1, 2, 3, 4 };

	l.emplace_back(5);	// Emplace at the back of the list.

	l.pop_back();	// As always, pop methods return nothing! So get the element before popping it!

	std::cout << l;
}

//int main() {
//	working_with_back_of_list();
//}