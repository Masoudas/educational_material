/**
* There is a function in list, called merge (merge as in merge step of the merge sort algorithm). Using this function, we 
* can merge two sorted lists together. Go figure! The function empties up the list to be merged in our current list. 
* 
* Question: Can't we use the merge algorithm of std? Yes we can, but it requires memoey use. We need to create a larger
* list, then use the merge algorithm.
*/

#include <forward_list>
#include <iostream>
using namespace std;

void merge_two_lists_in_new_list() {
	forward_list<int> f1{ 1, 2, 3 };
	forward_list<int> f2{ 4, 5, 6 };

	
	f1.merge(f2, [](const int& _Left, const int& _Right){ return _Left < _Right; });

	std::copy(f1.cbegin(), f1.cend(), std::ostream_iterator<int>{std::cout, " "});
}

//int main() {
//	merge_two_lists_in_new_list();
//}