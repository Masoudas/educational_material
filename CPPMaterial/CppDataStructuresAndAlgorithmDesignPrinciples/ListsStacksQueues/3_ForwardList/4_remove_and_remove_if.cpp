/**
* forward_list provides two other functionalities for removing elements:
* 
* 1- remove(): Removes all elements that are equal to this value, using the == operator of the underlying
*	type. Note that it has to be const function.
* 2- remove_if(): Remove all elements based on the given predicate. Hence, this remove does not use the equal
*	operator. The predicate is function that takes a value of type and returns a bool.
* 
*/

#include <forward_list>
#include <algorithm>
#include <iostream>

struct val {
	int x;

	bool operator==(const val& right) noexcept {
		return x == right.x;
	}

	bool operator==(const val& right) const noexcept {
		return x == right.x;
	}
};

void removing_elements() {
	using list = std::forward_list<val>;

	list l{ val{1}, val{2}, val{3}, val{1}, val{4}, val{1} };
	l.remove(val{ 1 });	// remove all elements equal, and returns the size of the remaining list.

	std::for_each(l.cbegin(), l.cend(), [](val v)->void {std::cout << v.x << "\t"; });
}

void remove_if_elements() {
	using list = std::forward_list<val>;

	list l{ val{1}, val{2}, val{3}, val{1}, val{4}, val{1} };

	l.remove_if([](const val& ref)->bool { return ref.x == 1; });
	std::for_each(l.cbegin(), l.cend(), [](val v)->void {std::cout << v.x << "\t"; });
}

//int main() {
	//removing_elements();
//	remove_if_elements();
//}