/*
* Built-in types have default and copy constructors.
* 
* Default constructor sets built-in types to zero, and nullptr for pointers.
* 
* Note that for built-in arrays, {} is the default constructor as well. (Me: which is the initilizer list.
* It initializes all elements to {} of the type). If no bracket is provided, the memory is randomly allocated.
* 
* Copy actually copies the value, with no reference to the original value.
* 
*/
#include <iostream>
using namespace std;

void initialization_of_built_in_types() {
	int buf[10]{};
	cout << "buffer of ints with default {} has default values: " << buf[5] << endl;

	int buf1[10];
	cout << "buffer of ints without default {} has random values: " << buf1[5] << endl;

}

//int main() {
//	initialization_of_built_in_types();
//}