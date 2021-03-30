/*
* One distinction that need to be made between an initializer list in a constructor and in a method
* is that with methods, we can't type x1, x2, x3 and conclude that it will be passed to initializer list.
* We need to use brackets for that purpose. However, the constructors allow us to do so, to simplify
* object construction, IF AND ONLY IF we have an initializer list in the constructor (and not any other
* parameters).
* 
* Me: It's very important to stress that not any other parameters. See 5, mixing_init_list_with_other_arguments
* and the examples below.
*/
#include <iostream>
#include <string>
using namespace std;
struct my_struct {
	my_struct(initializer_list<int> l) { cout << "Inside initializer list constructor" << endl; }
	my_struct(string s, initializer_list<int> l) { cout << "Inside string and initializer list constructor" << endl; }
	static void method(initializer_list<int> l) { cout << "Inside initializer list method" << endl; }
};

void using_initializer_list() {
	my_struct s1{ 1, 2, 3 };	// Yes. We're using an implicit constructor, and we're not repeating the

	// the brackets for initializer_list.
	// my_struct s2{ "", 1, 2, 3 }; Error. Can't distinguish where initializer list starts and ends.
	my_struct s2{ "", {1, 2, 3} }; // Ok. Using string together with initializer list 

	// my_struct::method(1, 2, 3); This is wrong. Passing three arguments.
	my_struct::method({ 1, 2, 3 });	// This is Ok!

}