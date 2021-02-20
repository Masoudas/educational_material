/**
* If we're sending a type inside the class using typename, we need to instantiate the type, otherwise
* we can use the value directly.
* A simple example is the following class:
*/
#include <iostream>
using namespace std;

template<typename T, int val>
struct type_and_val {
	void f() {
		int w = val;	// I can use val as is passed inside.
		T t{};	// I have to instantiate the integer type.
	}
};

/**
* When is this most relevant? Imagine we want to pass a function in template, like greater than equal for a template U.
* We cannot define a signature bool(*)(U, U) in the template, as this is illegal. instead we ask for a type,
* and we conway to the user that this type must implement the operator. How do we do this? For example, we can
* create an auxiliary class that has the operator implemented. Then we set that as the default value of the template.
* The point here is that this a type. So if we want to use this template type, we HAVE to INSTANTIATE at some point.
* We cannot pass an instance with typename templates. We're just passing a type.
* Note that the auxiliary class's geq operator now has this problem that it's not binary. Hence, the commented
* piece of code does not work. Hence, we need to actually use the functional interface to make it work!
* 
* 
* Note: For the geq of this example and other similair examples, we can use std functional classes such as 
* greater_equal<T>, again passing them as type. 
*/


//template<typename T>
//struct geq {
//	bool operator>=(T a2) {
//		return a1 >= a2;
//	}
//};
//
//template<typename U, typename GEQ = geq<U>>
//struct function_templates {
//	void f(U u1, U u2) {
//		GEQ geq{};	// We need to instantiate the type that has geq first. This has been indicated using
//					// our geq template.
//		geq.operator>=(u1, u2);	// This does not work!!
//	}
//};

//------------------------------------------------------
template<typename T>
struct geq_professional {
	bool operator()(T a1, T a2) {
		return a1 >= a2;
	}
};

template<typename U, typename GEQ = geq_professional<U>>
struct function_templates_professional {
	void f(U u1, U u2) {
		GEQ geq{};		// Again, we need instantiation.
		geq(u1, u2);	// Using the functional interface of the class!
	}
};
