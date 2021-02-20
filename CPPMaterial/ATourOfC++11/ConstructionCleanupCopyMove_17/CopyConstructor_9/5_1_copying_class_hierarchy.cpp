/*
* How does one copy a hierarchy of classes?
* An example is shown below, where we copy the portion of class assoicated with S1 using its copy constructor.
* 
* (Me: in what follows, a virtual base means a base that is inherited as virtual, not a base with virtual method)
* A virtual base may appear as a base of several classes in a hierarchy. A default copy constructor
* will correctly copy it.  If you define your own copy constructor, the simplest technique is to 
* repeatedly copy the virtual base. Where the base object is small and the virtual base
* occurs only a few times in a hierarchy, that can be more efficient than techniques for avoiding the
* replicated copies. (Note that a purely virtual class cannot be d
*/
#include <string>
#include <iostream>
using namespace std;

struct S1 { 
	string s; 
	S1(string s1) : s( s ) {}

	S1(const S1& ref) {
		cout << "Using copy constructor of base" << endl;
	}
};

struct S2 : S1
{
	S2(string s1) : S1{ s1 } {
	}
	S2(const S2& ref) : S1(ref) {

	}
};

//int main() {
//	S2 s1{ "Hey"};
//
//	S2 s2{ s1 };
//}