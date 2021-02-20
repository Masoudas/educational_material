/*
* So, when we declare an array const, we expect not to be able to write to it. Moreover, we expect that iterators
* are consts, in the sense that we can't write through iterators as well. This is taken care of, by noting that
* for every member there's an equivalent const override (like const T& at(int) const), ensuring this very 
* property). Note also that front method returns a const iterator, and back returns a const T&, and data 
* return a pointer to constant. Of course, the same story goes for constexpr array as well
* 
* In conclusion, when declaring a container constant, we expect not to be able to write to it, and the iterator
* methods should return a const iterator as well. 
* 
* One thing that should be noted about the implementation of array is that it does not keep two pointers,
* one for const and for normal. It's only the access methods to that const that change with the postfix qualifiers.
*/

#include <array>
#include <iostream>
using std::array;

void const_usage() {
	const array<int, 4> arr{ 1, 2, 3, 4 };

	// arr[0] = 4; Nope! Attempting to write to a const vector
	//arr.at(3) = 4; Impossible, trying to write to const int&,
	const array<int, 4>::const_iterator itr = arr.begin();	// Returns a const iterator, not possible to write.
}
