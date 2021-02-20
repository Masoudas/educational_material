/**
* As we already know, a list cannot be sorted like a normal array, given that we can't have access to
* each element directly. Instead, we use natural sort together with the merge sort algorithm (see Sedgewick
* exercies of merge sort). Note that this implies that we can't sort a forward_list using qsort or other
*  sort methods of stl.
* 
* The forward list provides a sort method for us as a member function. It either uses the
* < operator, or it uses a function pointer (which can be the std::less for example).
* 
* Interestingly enough, sort does not work with less_equal or greater_equal. The equal sign seem to
* mess up the sort! Why? For one thing, the sort is supposed to be stable. Hence, an equal sign would
* change two equal elements. There's actually a macro in the debugger of sort that checks so that
* the predicate is less, or greater (and not equal. The macro checks whether the fp returns true for
* comparing the same element) Note however that as expected, this exception is not
* thrown in Release mode, making the algorithm unstable! As a reminder, the pivot sort is an unstable 
* sort algorithm, given that we exchange two equivalent keys.
*/

#include <forward_list>
#include <algorithm>
#include <sstream>
#include <iostream>

void sort_with_operator() {
	using list = std::forward_list<int>;
	list l{ 4, 2, 3, 1, 4, 1 };

	std::ostringstream o{};
	o << "Sort using empty sort function\n";

	l.sort();
	std::for_each(l.cbegin(), l.cend(), [&](int n){o << n << "\t"; });
	
	o << "\nSort using a predicate\n";
	l.sort(std::greater_equal<int>());
	std::for_each(l.cbegin(), l.cend(), [&](int n){o << n << "\t"; });
	std::cout << o.str();
}

//int main() {
//	sort_with_operator();
//}