/*
* Say a method has an overload with rvalue reference. Assume we're passing the object itself (i.e, its lvalue)
*  Which version of it does C++ use if:
* 1-	The argument has move constructor?
* 2-	The argument has no move constructor?
* 
* The answer is C++ does not make decisions for us. It will use the method with lvalue, because we didn't declare (say
* with std::move) that we want this object moved. 
* 
* Also, when an object is passed by rvalue or lvalue reference, no assignment operator is called inside the function.
* Only the value is directly available for the method!
* 
* Conclusion: UNLESS we declare our object as temporary, C++ does not do it for us.
* 
* When will C++ uses move constructor or assignment inside a method? If an actual construction with rvalue reference
* takes place, as well as an assignment. Moreover, if an object is temporary and we want to return it from the method
* and it has a move constructor (which is not likely, because with heap objects, we normally return pointers).
* 
* (Me: Let me put it this way. Defining an rvalue reference is like defining a normal reference. Hence, an 
* expression like T&& x = v is nothing but saying we're now holding a reference to it. IT'S ONLY WHEN WE PUT THIS
* x ON THE RIGHT HAND SIDE OF AN OBJECT THAT MOVE SEMANTICS COME INTO EFFECT).
*/
#include <iostream>

using namespace std;
class A {
public:
	A(){}
	A(const A& ref) { cout << "Inside copy constructor" << endl; }
	A(A&& ref) noexcept { cout << "Inside move constructor" << endl; }
	A& operator=(A&& ref) noexcept{ cout << "Inside move assignment" << endl; }
	A& operator=(const A& ref) noexcept { cout << "Inside direct assignment" << endl; }
};

void method_accepting_rlvalue_ref(A&& a) {
	 cout << "Inside method with rvalue argument" << endl; 
}

void method_accepting_rlvalue_ref(A& a) {
	cout << "Inside method with lvalue argument" << endl;
}

//int main() {
//	A a{};
//
//	method_accepting_rlvalue_ref(a);
//
//	cout << endl << "Now declaring the object temporary: " << endl;
//
//	method_accepting_rlvalue_ref(std::move(a));
//}
//
//
