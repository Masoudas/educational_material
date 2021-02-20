/**
* By rotating an array, we mean a circular rotation where the last element rotates to become the first 
* element. std::rotate takes care of this rotation for us. It accepts (first, n_first, last). The way it
* rotates is such that n_first (new first) becomes the new first element, and n_first-1 becomes the new
* last element. Note that counter rotate is the same as rotate, only negative.
* 
* std::reverse reverses a collection for us. Note that list collections either can't be reversed (like
* forward list) or have their own reverse (like list). There's a reverse_copy that returns a copy of the
* reversed collection in a collection of our choice.
*/
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <execution>

void rotate() {
	std::vector<int> v{ 1, 2, 3, 4 };
	std::rotate(v.begin(), v.end() - 2, v.end());	// Put the first to last on top (rotating by two).

	std::ostringstream o{};
	o << "Shifted twice vector is \n";
	std::for_each(v.begin(), v.end(), [&](const int& v) {o << v << '\t'; });

	std::cout << o.str();
}

void reverse() {
	std::vector<int> v{ 1, 2, 3, 4 };
	std::reverse(v.begin(), v.end());

	std::ostringstream o{};
	o << "Reversed vector is \n";
	std::for_each(v.begin(), v.end(), [&](const int& v) {o << v << '\t'; });

	std::cout << o.str();
}

void reverse_copy() {
	// We try and reverse a vector, and then put it in a list.
	std::vector<int> v{ 1, 2, 3, 4 };
	std::list<int> l(v.size());

	// Because we're so cool, we do it in a parallel manner.
	std::reverse_copy(
		std::execution::par, v.begin(), v.end(), l.begin());	// Yeah! This has the problem that it needs an 
 										 // allocation and then an assignment to do the reversing and copying.
	
	std::ostringstream o{};
	o << "The reversed vector as a list is: ";
	std::for_each(l.begin(), l.end(), [&](int v) { o << v << "\t"; });
	std::cout << o.str();
}

//int main() {
//	reverse();
//	reverse_copy();
//}
