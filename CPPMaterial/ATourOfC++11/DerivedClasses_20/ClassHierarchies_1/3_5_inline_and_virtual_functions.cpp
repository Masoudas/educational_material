/** This is me:
* 
* As we already know, an inline function copy pastes inside a function. Question is, what would happen if a
* virtual function is inlined? Well. As Bjarne says, the inlining property is saved with the scope operator.
* So at least at this point, I can't think of a scenario where inlining together with virtual functions may
* cause a problem.
* 
* Note: If you think this does not happen, remember that defining an in-place class method (rather that outside
* class definition) renders the method inline.
* 
*/
#include <iostream>

using namespace std;

struct my_base {
	virtual void f() { cout << "base f\n"; }
	virtual void g() { cout << "base g\n"; f(); }
};

struct my_derived :my_base {
	void f() override { cout << "derived f\n"; }
};

//int main() {
//	my_derived d{};
//
//	my_base* b = &d;
//	b->g();
//}