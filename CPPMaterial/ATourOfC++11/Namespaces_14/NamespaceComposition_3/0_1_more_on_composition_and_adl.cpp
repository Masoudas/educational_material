/**
* So imagine the following scenario, when I try to overload an operator of a type in NS1 in NS2. When trying
* to resolve for operator, which one is chosen below?
* 
* Obviously, the non-templated version is a better match for (X,X). For (X,Y), we see that no match is found,
* even though we have a templated version. Why? Apparently, this is an issue of the templated methods. Perhaps,
* we can't resolve ADL and template parameter list at the same time.
* 
* Note that all of this happens despite the fact that we use declarative of NS2 for our object construction.
* 
*/
#include <iostream>
using namespace std;

namespace NS1_H {
	struct X {};
	struct Y {};

	bool operator<(const X&, const X&) { cout << "Inside NS1_H operator\n"; return false; }
}

namespace NS2_H {
	using namespace NS1_H;

	template<typename T, typename T1>
	bool operator<(const T&, const T1&) { cout << "Inside NS2_H operator\n"; return false; }

	template<typename T, typename T1>
	void method(const T&, const T1&) {}

}


void composition_and_adl() {
	using NS2_H::X;
	using NS2_H::Y;

	X x{};
	Y y{};

	x < x;
	
	// method(x, y); Error! Needs explicit declaration..
	// x < y; Error! Needs explicit declaration.
}