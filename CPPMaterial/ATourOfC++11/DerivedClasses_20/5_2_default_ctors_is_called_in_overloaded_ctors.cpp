/**
* Which version of the base class constructor is called when we inherit a class? For example, in Java if a ctor 
* with int is created in the derived class and there's no corresponding one in the base, Java would complain and 
* not compile.
* 
* In C++, the story is different. If a new constructor overload is created in the derived class, the constructor 
* that is used from the base class is always the default one (assuming such a constructor exists), unless we 
* explicitly specify which constructor to use. In other words, if a default ctor does not exist, that's the only 
* time the derived classes do complain. 
*
* Now, another question that arises here is, what about the copy constructor? 
* Note that even for copy construction, we need to create the base part of the class. How is the question?
* Well, we can argue that for copying, we need to know how to copy the base class portion of our class, which is 
* possible by knowing the base class copy constructor. This is the default version of copy. 
* 
* This however is restrictive, and if we cound manage to construct the base class part, we'd be able to initialize 
* the base class invariants explicitly. In other words, a derived class constructor (regardless of which version 
* it is, an overload, copy ctor, etc) if not directed to use a particular version of the base class constructor 
* always uses the default ctor. 
*
* LoL point: In the following example, don't be surprised to see the base class message being printed first.
*/
#include <iostream>
using namespace std;

struct o_base {
	o_base() {
		std::cout << "Inside base class default constructor" << '\n';
	}

	o_base(const o_base&) = delete;

	o_base(int) {
		std::cout << "Inside base class int constructor" << '\n';
	}
};

struct o_derived : o_base{
	o_derived(int) {
		std::cout << "No explicit base ctor call. The base default was called.\n\n";
	}

	o_derived(int, int) : o_base(5) {
		std::cout << "In double int constructor, the int ctor of base class is explicitly called. \n\n";

	}

	o_derived(const o_derived&) {
		std::cout << "No constructor call in copy ctor of derived. Base is constructed using default. \n\n";
	}
};

void using_base_derived_with_overloaded_ctors() {
	o_derived o1{ 5 };

	o_derived o2{ o1 };

	o_derived o3{ 5, 5 };
}


//int main() {
//	using_base_derived_with_overloaded_ctors();
//}