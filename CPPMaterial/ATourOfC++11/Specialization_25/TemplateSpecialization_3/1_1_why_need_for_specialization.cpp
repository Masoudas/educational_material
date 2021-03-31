/**
* By default, a template gives a single definition to be used for every template argument (or combination of 
* template arguments) that a user can think of. This doesn’t always make sense for someone writing a template. 
* I might want to say, "If the template argument is a pointer, use this implementation; if it is not, use 
* that implementation," or "Give an error unless the template argument is a pointer derived from class 
* My_base." Many such design concerns can be addressed by providing alternative definitions of the template 
* and having the compiler choose between them based on the template arguments provided where they are used. 
* Such alternative definitions of a template are called user-defined specializations, or simply user 
* specializations
* 
* Me: This discussion begs a question. Can we bound the template to an interface using templates? The answer is a 
* resound NO, with an stipulation. So imagine in the following example, we define an specialization for the base*.
* It's true that now, the templated class can only be initialized with the base* (because the actual definition of the
* class does throw.) However, this templated class ONLY works with this pointer template. In other words, if we try
* and instantiate this class with derived* (or an int* for that matter,) the specialization to base* is not invoked.
* Therefore, NO, we can't bound the template to an interface as such. However, note that if we actually have a ctor
* that for example takes T, then that T can be derived*, because an implicit conversion would take place from derived*
* to base*. Consequently, this method somewhat works, but not quite.
* This discussion once again brings an important point to our attention. Types are not objects. Therefore conversion
* among them when we use templates does not make sense. Hence for example, a template that is specialized for type base 
* is NOT instantiated for the derived type.
*/
#include <iostream>

struct base {}; struct derived : base{};

// We need the basic type. Throws an exception!
template<typename T>
struct templated {
	templated() {
		throw "Can't build unless has base* in template";
	}
};

// The specialization only allows for base type!
template<>
struct templated<base*>{
	templated() {
		std::cout << "Ok to build the type";
	}
};


void instantiation_of_templated() {
	templated<base*> t1{};

	templated<derived*> t{}; // Will throw!	
	//templated<int> t{};	// Will throw!
}

//int main() {
//	instantiation_of_templated();
//}
