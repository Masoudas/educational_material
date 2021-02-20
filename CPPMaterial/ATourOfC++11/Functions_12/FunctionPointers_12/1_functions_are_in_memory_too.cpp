/**
* Like a data object, a function is also in memory. Hence, we can define a pointer that points to it.
* (Note that this is different for member functions). For various reasons however, a pointer to function
* does not allow modification of memory. There are only two things we can do with a function,
* call it, or take its address. Note that the use of dereferencing operator or address operator are optional.
* 
* The rules for passing arguments through function pointer and normal call are the same (including conversions,
* using copy, etc).
*/
#include <string>
#include <iostream>
using namespace std;

void error_for_fptr(string str) {
	cout << "inside err" << endl;
}

void error1_for_fptr(string str) {
	cout << "inside err1" << endl;
}

void using_fptr() {
	void (*fp)(string str) = error_for_fptr;
	fp = &error1_for_fptr;

	fp("");
	(*fp)("");
}

//int main() {
//	using_fptr();
//}