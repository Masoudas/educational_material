/**
* The most significant difference between forward_list and list insert function is that there's no after
* associated with them. Why? Because we can simply place an element right between two nodes, given that
* a list is doubly linked.
* 
* So, where will the item be placed after all? Well, when we place it at the ith location, it will become the
* ith item of the list, pushing iterm i to i+1th place.
*/

#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>

using std::list;

void insertion_and_emplace_in_list() {
	list<int> l{ 1, 2, 3, 4 };

	l.emplace_back(5);	// Emplace at the back of the list.
	
	auto begin = l.cbegin();
	std::advance(begin, 2); // Placed on three
	l.emplace(begin, 6);	// The list is now 1, 2, 6, 3, 4, 5

	std::ostringstream o;
	std::for_each(l.cbegin(), l.cend(), [&](int v) {o << v << '\t'; });

	std::cout << o.str();
}

//int main() {
//	insertion_and_emplace_in_list();
//}