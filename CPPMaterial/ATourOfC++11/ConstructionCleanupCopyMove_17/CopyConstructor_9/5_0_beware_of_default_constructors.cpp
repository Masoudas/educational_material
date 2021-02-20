/**
* When copying, ensure that every base class member is also copied. For example, in the following class,
* s2 is initialized to "" (because member initialization with {}), which is not the intent.
* 
* Then again, we can see why default operations are preferable. If one adds a parameter in the future, we may forget
* to add it to our custom copy constructor.
* 
* The y is also initialized with{} below in the copy constructor.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class X {
	string s;
	string s2;
	vector<string> v;
public:
	int y;
	X(const X& a) // copy constr uctor
		:s{ a.s }, v{ a.v } // probably sloppy and probably wrong
	{
	}
	X(int y) : y(y){}
	// ...
};


//int main() {
//	X x{1};
//	X x1{x};
//
//	cout << x1.y;
//
//}