/**
* Note again that constructor and destructor of array are all default ones. Consequently,
* The copy constructor of array  perform a deep copy. This is a deep copy, in the sense that it calls 
* the copy constructor of every element. Hence, if we pass an array by copy to a function, it deep copies
* every element.
* 
* In fact, if an element cannot be copied, the compiler throws an error.
* 
* Copy assignment also copies the old array into the new one.
*/
#include <array>
#include <iostream>

struct X {
	X() = default;
	X(const X& ref) { std::cout << "Calling the copy constructor\n"; }
};


void copy_constructor_array() {
	using namespace std;
	
	array<X, 2> arr{ X{}, X{} };

	array<X, 2> arr_cp{ arr };


}

//
//int main() {
//	copy_constructor_array();
//}