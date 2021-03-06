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
* Me: This discussion gives us a big hint as to how we can bound the template to a particular type (interface.)
* For example below, we use specialization to throw an error for which ever type that cannot be converted to
* our interface, by just throwing an exception in the template definition. Question, however, is that is this
* among C++ design patterns? Or am I again thinking in Java terms here! Also note that we only need the
* interface for templated here, and if it's not being used, then it shouldn't necessarily be defined, and
* it can be left without implementation! See discussion in 4_3.
* 
* 
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

	templated<int> t{};	// Will throw!
}

//int main() {
//	instantiation_of_templated();
//}