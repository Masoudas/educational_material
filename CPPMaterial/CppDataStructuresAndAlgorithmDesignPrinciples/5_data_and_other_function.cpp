/**
* The data method of array returns a pointer to the underlying array. It can be used in lieu of 
* &arr[0].
* 
* Now that we're here, we should talk about some other methods:
* 1-	empty(): Checks whether begin()==end(). i.e, whether the array is empty, or has no elements.
* 2-	front() and back() return the element at front and back (not as pointer, but rather actual value).
* 
* There's also a number of operational methods:
* 1-	fill: Fills every elements of the array with the given one.
* 2-	swap: swaps the content of this container with the other. Does not cause reference or iterator binding
*	with the other one.
* 
* There's also a max_size(), which returns the maximum storage size of the vector possible, based on the
* implementation, and system (i.e, distance(begin, end))
*/
#include <array>
#include <iostream>

using std::array;


void working_directly_with_underlying_array() {
	array<int, 3> arr{ 1, 2, 3 };

	int* c_arr = arr.data();

	array<int, 3> arr_n{ 0 };	// Sets all elements to 0. This is memberwise initialization, not an
								// initializer list constructor. Recall that the class has no constructor!

	arr_n.swap( arr );
	arr.fill(1);	

	std::cout << "arr_n is the content of arr [" << arr_n[0] << '\t' << arr_n[1] << '\t' << arr_n[2] << "]\n";
	std::cout << "arr is now a uniform array [" << arr[0] << '\t' << arr[1] << '\t' << arr[2] << ']';
}

//int main() {
//	working_directly_with_underlying_array();
//}