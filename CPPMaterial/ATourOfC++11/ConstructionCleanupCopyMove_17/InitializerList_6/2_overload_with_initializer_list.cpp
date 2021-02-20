/*
* For a class, the usuall overload resolution rules take place. However, initializer list and
* default constructors take precedence over other constructors. This why for example for containers,
* saying vector<int> v{10} creates a vector with 10, rather than a vector with 10 elements.
* 
* (Me: With functions, because we use (), there would be no ambiguity. We'd use {} for initializer list.
*	Note that supplying arguments without brackets to an initializer list in a function is impossible.)
* 
* If either a default constructor or an initializer-list constructor could be invoked, prefer the
* default constructor. This is common sense, as it chooses the simplest constructor

*/
#include <iostream>
using namespace std;

struct with_initializer_list {
	with_initializer_list() { cout << "Inside the default constructor" << endl; }
	with_initializer_list(int i) { cout << "Inside the int constructor" << endl; }
	with_initializer_list(initializer_list<int> l) { cout << "Inside the initializer list constructor" << endl; }

	void f(int i) { cout << "Inside the int function" << endl; }
	void f(initializer_list<int> l) {
		cout << "Inside the initializer list function" << endl;
	}
};

void initializer_list_or_single_element() {
	with_initializer_list c{ };	// Between default an initializer list, initalizer list is chosen, naturally!

	with_initializer_list c1{ 10 };	// Initializer list constructor takes precedence.

	with_initializer_list c2( 10 ); // Invoking constructor. Inside int constructor.

	with_initializer_list c3({ 10 }); // Inisde list constructor.

	c3.f(10);	// Inside int method.
	c3.f( {10} );	// Inside initializer list (not creating an int).
	// c3.f( 10, 20, 30 ); Error! No brackets are found.
	c3.f({10, 20, 30});
	c3.f({});	// Not ambiguous! Resolved to initializer list! I would've guessed either ambiguous or int method!
}

//int main() {
	//initializer_list_or_single_element();
//}