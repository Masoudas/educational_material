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

	my_container c3 = { 1 };	// Will not be confused with int constructor.
	my_container c4{ 1 };	// Initializer list takes precedence.

	my_container c5(1);		// Int constructor.
}

//int main() {
//	my_container_initialization();
//}