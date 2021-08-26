/**
* Just as a reminder, when a variable is not intialized, the = {} operation uses
* the constructor (in particular an implicit conversion). However, if initialized, it uses assignment operator.
* 
* Note that T t = T{} uses a move (but I've read that some compilers optimize it.)
*/

#include <iostream>
using namespace std;

struct example{
	example(int j) { cout << "Inside constructor" << endl; }
	example(example& ref) { cout << "Inside copy constructor" << endl; }

	example& operator=(example& ref) { cout << "Inside assignment constructor" << endl; return ref; }
};

//int main() {
//	example e1 = { 1 };
//
//	e1 = e1;
//}