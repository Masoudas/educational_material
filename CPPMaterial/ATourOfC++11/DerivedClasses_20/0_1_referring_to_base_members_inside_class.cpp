/* This is me:
* Simply put, how can we point to the base class members when we're inside the derived class?
* 
* Answer: We can think of at least two different ways:
* 1-	We can use the scope operator. This is specially important for when the derived class hides the method from
*	the base class (scope).
* 2-	We can cast the this pointer to use the base class portion of the class. The issue with this approach
*	however is that we can't access the protected members of the base class.
* 
* We should have expected the use of scope operator for accessing the base class methods. After all, a class is 
* a scope in and of itself. Hence, using the scope operator for accessing the base part of the scope does make
* sense. 
* 
* It's often useful to think about class as merely scopes that can be instantiated. Hence, a derived class is a scope
* nested inside another scope. To access the (static or non-static) members of the base, we need to use the scope
* operator. This is perhaps another reason why we use the scope operator to define a class member outside its
* definition.
*/
#include <iostream>
using namespace std;

struct base {
	void pub() { cout << "Inside base class public method\n"; };
protected:
	int x;
	void protec() { cout << "Inside base class protected method\n"; };
};

struct derived : base{
	void g() {
		int w = base::x;
		base::protec();

		base* b = this;
		// b->protec(); Error! This is protected!
		b->pub();
	}
};

//int main() {
//	derived d{};
//	d.g();
//}