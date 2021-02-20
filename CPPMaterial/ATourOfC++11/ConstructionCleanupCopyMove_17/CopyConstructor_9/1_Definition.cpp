/**
* Copy constructor and copy assignment have the following notions for class X:
* X(const X&)
* X& operator=(const X&)
* 
* We can get more adventurous with the types and for example add volatile. But we must not, because it
* will confuse on a syntax level (not compiler level).
* 
* For example, we can return const X& from equal, but then again, we shouldn't do that.
* 
* In the following example, we're overriding the copy constructor. But we should be aware that it's not 
* the copy constructor.
* 
* NOTE: As we discussed in 5_when_class_default_operations_are_removed, defining one custom constructor operation,
* (like copy constructor here) the other one (at least in VS). Hence, adding other keywords to
* such operations (such as defining copy constructor as X(X& x)) DOES NOT overload the copy constructor. It just removes
* that operation (As we may recall, only plain types with no reference or pointer cannot be overriden by const
* keyword. Hence, we actually expected to have overloaded the copy by removing const keyword).
*/
#include <iostream>
using namespace std;
struct X {
	X(int x){}
	X(X& x) { cout << "This is not copy constructor, but still works" << endl; }
};


void calling_copy_constructor() {
	X x{ 1 };
	X y{ x };
	
	x = y;
}
