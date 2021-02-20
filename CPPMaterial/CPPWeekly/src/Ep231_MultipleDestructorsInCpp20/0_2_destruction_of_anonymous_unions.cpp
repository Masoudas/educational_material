/**
* When an anonymous union is present in the class, it cannot be destructed trivially. Why? Because the question
* for the compiler would be "which destructor should I use"? This is a question the compiler can't answer, because
* the compiler does not keep track of the active union member. Hence, we need to define the destructor.
* 
* Actually, before C++11, we couldn't put a type with non-trivial destructor in anonymous unions.
* 
* Notice how bizarre the call to destructor is in fact! We have to call it this way, because s is not determined
* to have been used.
*/

#include <string>

struct has_union {
	union {
		std::string s;
		int i;
	};	// Size of the union is the size of the string.

	bool has_string = false;

	~has_union() {
		if (has_string) {
			s.~basic_string();
		}
	}


};

void using_has_union() {
	has_union s{};	// Now this is created just fine. Without explicit destructor, impossible to create on stack!

}