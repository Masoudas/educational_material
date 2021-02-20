/**
* We need a constructor to set the invariants of a class. The destructor does the reverse, and frees the 
* resources used by the invariants (files, locks, memory, ...).
* 
* When destructor is called, every destructor that can be called is called. The resource that are not
* destroyed are ones for which no destructor can be called directly (like a pointer. The class frees
* the memory associated with the pointer, but not the content of the pointer).
* This is shown in the follwing example. The destructor of both str and str_ptr are both called. 
* However, the destructor of the pointer only removes the poiner, not its content, which 
* is why we get only one destructor removing message. Note that when writing a destructor, we
* don't need to write str.~string(). This is done automatically by the destruction process of 
* the class.
*/
#include <iostream>
using namespace std;

struct string {
	~string() { cout << "Calling string destructor" << endl; }
};

struct Dest_Call {
	::string str{};
	::string* str_ptr = new ::string;

	~Dest_Call() { cout << "Initializing destruction" << endl; }
};

//int main() {
//	Dest_Call dest{};
//}