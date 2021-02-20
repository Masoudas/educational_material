/**
* The basic structure of a linked list requires us to have a pointer and to manage memory 
* allocation and deallocation manually using the new and delete operators. Although it is 
* not difficult, it can lead to bugs that are difficult to trace. Hence, just like std::array 
* provides a thin wrapper over C-style arrays, std::forward_list provides a thin wrapper 
* over a basic linked list. (Does not seem to be the case with MSVC. Note also that forward
* in the name implies singly linked list, holding only the first node).
* 
* The purpose of std::forward_list is to provide some additional functionality without 
* compromising performance compared to a basic linked list. To maintain performance, 
* it doesn't provide functions to get the size of the list or to get any element but the first 
* one directly. Hence, it has a function called front() to get the reference to the first 
* element, but nothing like back() to access the last element. It does provide functions 
* for common operations, such as insertion, deletion, reverse, and splice. These functions 
* don't affect the memory requirements or performance over basic linked lists.
* 
* We can also supply a custom allocator.
* 
* As a side note, forward_list is not a constexpr class. This does make sense, because how are you going to
* write a constructor that holds pointers at different locations of memory? It can be done, but way too complicated,
* and has no particular use for us, especially given that we can't change values. An array would suffice.
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

void construction_of_list() {
	forward_list<int> f_list1( 2, 4 );	// Construct a list of two elements all equal to four. Note the paranthesis.
	print_list(f_list1.begin(), f_list1.end());

	forward_list<int> f_list2{ 1, 2, 3, 4 };	// Initializer list constructor
	print_list(f_list2.begin(), f_list2.end());

	// Templated constructor, accepting iterator.
	vector<int> vec{ 1, 2, 3 };
	forward_list<int> f_list{ vec.begin(), vec.end() };
	print_list(f_list.begin(), f_list.end());

	forward_list<int> f_list3{ f_list };	// Takes a full independent copy of f_list.


}

//int main() {
//	construction_of_list();
//}
