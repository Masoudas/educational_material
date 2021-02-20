/**
* There's a contradiction when using rvalues. For example, for a class X, I can say:
* X&& r = std::move(v);
* y = r;	// Move assignment!
* X&& r2 = r;	// Error!!!
* 
* In other words, the rvalue reference does its job when it's supposed to, but I can't copy it! Why?
* Note that as soon as we define an rvalue references, we're assigning a name to an entity. Hence, we can't
* reassign an rvalue reference to another rvalue reference, because now it's an lvalue.
* int&& rval = 1;
* int&& rval_2 = rval;	// Error! Binding an lvalue to an rvalue!
* 
* To remedy this issue, we need to use std::forward to bring back the rvalueness of the reference (or, just
* use std::move once again, although it does not convey the same notion).
* 
* And since you're interested, the following is fine:
* const X& cl = r;
* Because we're assigning a non-const lvalue to a const one.
* 
* 
*/

#include <iostream>
#include <memory>

struct MyStruct
{
	int x;
};


void overloaded_with_lref_and_rref(MyStruct& ref) {
	std::cout << "lvalue function is called" << std::endl;
}

void overloaded_with_lref_and_rref(MyStruct&& ref) {
	std::cout << "rvalue function is called" << std::endl;
}

void rvalue_reference_becomes_lvalue(MyStruct&& ref) {
	ref.x = 10;	// ref in and of itself is an lvalue, allowing us to write to value.
	
	overloaded_with_lref_and_rref(ref);		// Now ref is an lvalue ref, so the lref function is called.

	overloaded_with_lref_and_rref(std::move(ref));	// Now call rval method.

	// Or we can forward the lvalue, although the use is not for here.
	overloaded_with_lref_and_rref(std::forward<MyStruct>(ref));	// Now call rval method.

	const MyStruct& cl = ref;	// Fine! Assigning a non-const lvalue to lvalue reference.
}

//int main() {
//	//MyStruct s1{};
//
//	//rvalue_reference_becomes_lvalue(std::move(s1));
//
//	//std::cout << s1.x;	// Because rvalue turned into an lvalue again, we see the changes here.
//}