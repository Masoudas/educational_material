/**
* We use the ~ to mean complement (of construction) for destruction.
* 
* Destruction must guarantee that every resource not freed by the class destruction procedure
* itself is destroyed.
* 
* Destructors are called implicitly when an automatic variable goes out of scope, an object 
* on the free store is deleted, etc. Only in very rare circumstances does the user need to 
* call a destructor explicitly 
* 
* Again, if new fails in construction, a bad_alloc is thrown and only the memory allocated by
* new thus far is deleted. 
* 
* This style of construction/destruction is known as RAII.
* 
* A programmer who declares a destructor for a class must also decide if objects of that class can
* be copied or moved. Yet, this is not enforced, or properly warned against, as is the case
* here in Visual Studio. So, be careful! (Unless VS does it for us in any case!)
* 
* To avoid this case, we use the keyword default alongside the default stuff, to ensure that the
* default methodology is used. See section Generating_Default_Operations_6 for more information.
*/
#include <iostream>

using namespace std;
struct has_destructor {
	int i;
	has_destructor() = default;
	has_destructor(has_destructor&) = default;
	has_destructor(has_destructor&&) = default;
	has_destructor& operator=(has_destructor&&) = default;
	has_destructor& operator=(has_destructor&) = default;
	has_destructor(int i): i(i){}
	~has_destructor(){}
};

void overriding_destructor_removes_move_and_copy(){
	has_destructor a1{10};
	has_destructor a2{ a1 };
	has_destructor a3{ move(a2) };

	cout << a1.i << endl;
	cout << a2.i << endl;
	cout << a3.i << endl;
}

//int main(){
//	overriding_destructor_removes_move_and_copy();
//}