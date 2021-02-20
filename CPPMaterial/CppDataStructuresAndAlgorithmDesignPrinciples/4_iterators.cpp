/**
* When an array is declared as constant, the iterator functions return constant iterators,
* rather than normal iterators
* 
* Note also the use of reverse iterators, where we still use ++ or advance function to move from
* the back of the array.
*/

#include <array>
#include <iostream>

void declaring_constant_array() {
	using std::array;
	const array<int, 2> arr{2, 3};

	// arr[0] = 1; const ref& operator() const noexception, hence, assignment is not possible.

	array<int, 2>::const_iterator begin = arr.begin();	// Note that its const iterator, and not const.

	for (auto itr_rev = arr.rbegin(); itr_rev != arr.rend(); ++itr_rev)
	{
		std::cout << *itr_rev << "\t";
	}
}

//int main() {
//	declaring_constant_array();
//}