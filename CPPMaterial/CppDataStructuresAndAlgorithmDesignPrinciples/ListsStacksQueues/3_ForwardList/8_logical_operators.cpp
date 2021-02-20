/**
* Are there any logical operators overloaded on forward_lists? Yes, there are.
* 
* Note that as is the case for array, the <=> comparisons are in fact lexico-graphical.
*/

#include <forward_list>
#include <algorithm>
#include <sstream>
#include <iostream>

using std::forward_list;

void compare_for_equality() {
	forward_list<int> l1{ 1, 2, 3, 4 };
	forward_list<int> l2{ l1 };
	forward_list<int> l3{ 1, 2, 3 };

	std::ostringstream o;
	if (l1 == l2) o << "l1 is equal to l2\n";
	if (!(l2 == l3) && l2 != l3) o << "l1 is not equal to l2\n";

	std::cout << o.str();
}

void greater_than_equal() {
	forward_list<int> l1{ 1, 2, 3, 7 };
	forward_list<int> l2{ 1, 2, 5, 6 };
	forward_list<int> l3{ 1, 2, 3 };

	std::ostringstream o;
	if (l1 < l2) o << "l1 is lexico-graphically less than l2\n";
	if (l2 > l3) o << "l2 is lexico-graphically greater than l3\n";

	std::cout << o.str();
}

//int main() {
//	compare_for_equality();
//	greater_than_equal();
//}