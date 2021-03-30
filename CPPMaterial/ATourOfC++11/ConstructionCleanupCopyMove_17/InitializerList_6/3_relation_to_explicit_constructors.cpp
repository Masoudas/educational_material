/**
* Initializer list in a constructor can be declared both explicit and implicit.
* 
* Bjarne says the distinction between direct and copy initialization with {} is maintained (I think
* he's talking about explicitness and implicitness here).
* 
* I don't get the point of the beginning part of section 17.3.4.3.
*/
#include <iostream>

using namespace std;

struct my_container {
	my_container(initializer_list<int> l) { cout << "inside implicit initializer list constructor" << endl; }
	explicit my_container(int x){ cout << "inside explicit int constructor" << endl;  }
};

void my_container_initialization() {
	my_container c1 = { 1, 2, 3 };	// Calling implicit list initializer.

	my_container c2{ 1, 2, 3 };	// Calling explicit list constructor. 

	my_container c3 = { 1 };	// Will not be confused with int constructor. It has to be explicit.
	my_container c4{ 1 };	// Initializer list takes precedence, by the default overload resolution rules!

	my_container c5(1);		// Int constructor.

	// my_container c6 = 1; // Error! Does not explicitly use my_container!
	my_container c6 = my_container(1);	// Int constructor!
	my_container c7 = my_container{ 1 };	// init-list constructor takes precedence in resolution!
}

//int main() {
//	my_container_initialization();
//}