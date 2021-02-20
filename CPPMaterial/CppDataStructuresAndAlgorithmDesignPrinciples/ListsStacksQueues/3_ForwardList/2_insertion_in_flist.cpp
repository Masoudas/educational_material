/**
* There are a couple of functions here:
* 
* 1- push_front(): Place an element in front of the list.
* 2- insert_after(): Place an element after the given element. We don't have a push_back method, because
*  it would be redundant, and also we don't have direct access to the last element. As such, insertion 
*  and removal takes O(1).
* 
* As is the case for vectors, we have emplace_front() and emplace_after(), which are preferable over the above
* mentioned methods (although at least in the latest implementation, push_front and insert_after use emplace).
* 
* Note also that insertion methods return a pointer that points to the currently set element.
* 
*/

#include <forward_list>
#include <vector>
#include <iostream>

using std::forward_list;
using std::vector;
using std::cout;

template <typename _Itr>
void print_list(_Itr begin, _Itr end) {
	cout << "[";
	while (begin != end) cout << *(begin++) << "\t";
	cout << "]\n";
}

void insertion() {
	forward_list<int> f_list{ 1, 2, 3 };

	f_list.push_front(0);

	auto it = f_list.begin();	// Points to 0.

	f_list.insert_after(it, 6);	// Inserts 6 after 0.
	auto iterator = f_list.insert_after(it, 5);	// Don't forget that still points to 0 element, 
												// hence we have {0, 5, 6, ...}
	f_list.emplace_after(iterator, 7);	// Places 7 after 5.

	print_list(f_list.cbegin(), f_list.cend());

}

//int main() {
//	insertion();
//}