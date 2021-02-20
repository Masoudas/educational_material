/**
* There's a part of the standard that says:
* "If a delete-expression begins with a unary :: operator, the deallocation function’s name is looked up in global 
* scope. Otherwise, if the delete-expression is used to deallocate a class object whose static type has a virtual 
* destructor, the deallocation function is the one selected at the point of definition of the dynamic type’s 
* virtual destructor (12.4). 117 Otherwise, if the delete-expression is used to deallocate an object of class T or 
* array thereof, the static and dynamic types of the object shall be identical and the deallocation function’s name 
* is looked up in the scope of T."
* 
* Particularly it says for an array of T, the static and dynamic types are the same. Consequently, we can dellocate
* an array of derived class with base pointers! 
* 
* So two points here: First, this is so C++, as once again we can't do two things in one operation, one is to delete
* an array, and second is to call the proper constructor of a virtual type. 
* 
* Second, deary me. We can do the same operation with a single pointer, but not with an array! 
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
//	a_base* d = new a_derived[]{ a_derived{}, a_derived{}, a_derived{}, a_derived{} };
//
//	delete[] d;
//}