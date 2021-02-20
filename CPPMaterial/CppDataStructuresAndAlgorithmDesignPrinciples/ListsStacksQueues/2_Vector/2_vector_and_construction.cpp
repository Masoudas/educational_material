/**
* Vector lets us change the size of the underlying array, to tailor it to our needs.
* Here are some of the construction methods.
* 
* Note that size refers to the number of elements in the vector, which is not equal to capacity.
* Capacity is the total number of elements the vector can hold, before it requires reallocation.
* 
* Note: When we use the vec(n) constructor, the vector has to create objects. This constructor does
* not allocate pointer only (size would be equal to n after this construction).
* As we're now aware of how the construction of objects with allocators work, we should note that
* vec(n) does not work for objects that have no-arg constructors. Why? Because the allocator tries to 
* construct the object with no parameters, but because that is not possible, it throws an error!
*/

#include <vector>
#include <iostream>

using std::vector;
using std::cout;

struct X {
	X(int) {}
};

void vector_construction_methods() {
	vector<int> vec;	// Constructs a vector with default constructor. The size will be 0.
						// 0 is compiler dependent.
	cout << "Size is: " << vec.size() << '\n' << " and capacity is: " << vec.capacity();

	vector<int> vec1{ 1,2,3,4 };	// Constructs with the initializer list and allocator. There's no
									// membrwise construction here, as we have constructors.

	vector<int> vec2(10);	// Vector of 10 elements. Note that vec{10} uses initializer list construction.

	std::vector<int> vec3(10, 5);	// Declare a vector of 10, and set each element to 5.

	// vector<X> vec4(10); Error! Can't construct an array of objects with no no-arg constructor.

}

//int main() {
//	vector_construction_methods();
//}