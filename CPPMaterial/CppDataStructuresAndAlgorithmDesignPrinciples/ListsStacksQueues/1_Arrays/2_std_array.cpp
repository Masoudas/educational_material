/**
* std::array is a very thin wrapper around c-style array. It takes two templates, type and size.
* size is size_t, and not int or unsigned int!
* 
* Given that the destructor and contructor is default (hence no pointer deletion upon destruction), we 
* conclude that the array is not allocated on the heap by default.
* 
* The .at() function throws an out_of_range exception. Hence, if there's uncertainty involving access 
* to the array, we can use that. Hence, it's a bit slower than [].
* 
* As opposed to that, operator[] has undefined behavior for access with our of range index. It does not
* range check. Sometimes it throws error, othertimes not. 
* 
* Passing arrays to functions is more explicit as opposed to C-style arrays. If we want to pass an array of
* any size, we need to make the function generic.
*/
#include <array>
#include <iostream>

using std::array;
void array_usage() {
	std::array<int, 10> arr; // array of int of size 10 (Me: Built using default constructor for custom types).
	arr[0] = 1;                    // Sets the first element as 1.

	// What is the value of an element not already set? A location on memory is allocated without any construction
	// for built-in types. Hence, the value is random
	std::cout << arr[1] << '\n';

	try
	{
		arr.at(5) = 10;	// Assign to five
		int x = arr.at(11);
	}
	catch (const std::out_of_range&)
	{
		std::cout << "out of range exception\n";
	}

	try
	{
		arr[11] = 10;	// Throws runtime exception, access out-of-range.

	}
	catch (const std::out_of_range&)
	{

	}
}

template<size_t N>
void working_with_array(array<int, N> arr) {

}

//int main() {
//	array_usage();
//}