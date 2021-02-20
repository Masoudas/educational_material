/**
* Using the paranthesis guarantees that a constructor is used. Hence, if memberwise initialization is 
* possible, paranthesis do not allow or use that. It will only use a constructor.
*/
#include <iostream>
using namespace std;

struct no_construct {
	int i;
	int j;
};

void using_paranthesis_constructor() {
	no_construct c1();	// Gotcha! This is a function definition! So c1 is interpreted as function!
	no_construct c2{};
	// no_construct c2(1, 2);	Error! no such constructor. No memberwise initialization.

	cout << c2.i << endl;
	cout << c2.j << endl;
}

//int main() {
//	using_paranthesis_constructor();
//}