/*
* Finally, the mystery of direct initialization of invariants solved. It's actually called
* memberwise initialization.
* 
* If a class has NO CONSTRUCTORS (i.e, has only default constructors, even empty constructor
* is not allowed here), and ALL invariants are PUBLIC, then we can initialize using bracket notion.
* 
* Note: When we say direct initilization is impossible, we're talking about the case where we actually
* set the value of each parameter. The empty bracket situation should not be confused with this.
* 
* What about the order of parameters? In the order defined in the class.
* 
* When we write empty {} bracket, if the class:
* 1-	Has default constructor: Then all parameters are initialized with defualt constructor. Even array
*	is initialized to (proper) zero.
* 2-	Has non-default constructor: For this case, built-in types are randomly initialized. Other types
*	are initialized using their default values. This includes the array.
* 
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Direct_Invariant_Initialization {
	string s;
	int i;
	char buff[10];
	string s2;
	vector<int> vec{ 1, 2 };

};

struct Has_Default_Constructor {
	string s;
	int i;
	char buff[10];
	string s2;
	Has_Default_Constructor() {};
};


void direct_class_invariant_initialization() {
	Direct_Invariant_Initialization d1{ "CC", 1, "CC" };	// Note that the corresponding constructors of string and int are 
														// called.
	Direct_Invariant_Initialization d2{ d1 };		// This is a copy constructor.

	// Has_Default_Constructor d3{ " ", 1, " " }; Presence of empty (or any) constructor makes it impossible 
	// to have member-wise initialization.

	d2.s[0] = 'A';	// Question: Does this change d1 too? Nope. Because when copying using default constructor,
					// every member is copied using its default constructor (How? There's no reflection in C++.
					// So perhaps this is a machine level operation.)
	cout << d1.s[0] << endl;	// This prints C.
	cout << d2.s[0] << endl;	// This prints A.

}

void initialization_with_empty_bracket(){
	Direct_Invariant_Initialization d1{};
	cout << "For class with default constructor, empty bracket initializes all to empty" << endl;
	cout << "i is: " << d1.i << " and s is " << d1.s << " and buff is" << d1.buff[0] << endl;

	Has_Default_Constructor d2{};
	cout << "For class with non-default constructor, empty bracket initializes to random" << endl;
	cout << "i is: " << d2.i << " and s is " << d2.s << " and buff is" << d2.buff[0] << endl;
}

//int main() {
//	direct_class_invariant_initialization();
//	initialization_with_empty_bracket();
//}