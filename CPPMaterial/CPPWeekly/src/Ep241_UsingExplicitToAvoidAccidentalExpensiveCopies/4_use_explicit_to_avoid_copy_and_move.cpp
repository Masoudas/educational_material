/*
* As a trick, we can make both the copy and move constructor explicit. That way, the user of the object
* will not be able to pass the object neither as copy, nor as temp! Their only option is to pass as
* reference or as pointer! Suckers!
*/
#include <iostream>
#include <utility>

struct S{
	S(){};
	explicit S(const S& ref){}
	explicit S(S&& ref) noexcept { std::cout << "Inside move constructor"; };
};

void no_copy(S s2) {
	// no_copy_or_move({}); No implicit copy!
	// no_copy_or_move(S{}); No passing rvalue
}

void no_move(S&& s2) {
	// no_move(S{}); //Nope! Can't pass rvalue reference
	std::cout << "The object address has remained the same, so passed by reference" << &s2 << '\n';
}

//int main() {
//	S s2{};
//	std::cout << "Object address is" << &s2 << '\n';
//
//	no_move(std::move(s2)); // Why would this one work? Because S s = move(S); does not work!
//							// True. But we have said that this object is nullable. So what C++ does is that
//							// it says, Ok, now that I can't create a new object, I'll just pass this by reference.
//							// So, the move would still be working, but no new object is created.
//						    // Note that we can't do this with a temp object (saying no_move(S{})), because
//							// we can't write to temp objects!!!
//
//}