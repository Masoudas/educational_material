/**
* As we already know, deleting a derived class with base pointer is perfectly fine. In fact, this is the one reason
* why we define a base class constructor virtual, so that the proper destructor is called in the hierarchy.
*/
#include <iostream>

struct a_base {
	virtual ~a_base() {
		std::cout << "Inside base class destructor\n";
	}
};

struct a_derived : a_base
{
	~a_derived() override {
		std::cout << "Inside derived class destructor\n";
	}
};

//int main() {
//	a_derived* d{ new a_derived{} };
//
//	delete d;
//}