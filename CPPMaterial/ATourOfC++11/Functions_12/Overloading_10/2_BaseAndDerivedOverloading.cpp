/*
* A class is a scope above all. Hence, When we have a base and derived class, 
* a function (that is not virtual) hides the name of base functions, rather than overriding it. 
* 
* If however we don't hide the function name, we'd get the base function.
* 
* Note however that if we try to access the method using base class reference, we'd get the base
* class method. (me: I think this happens because the base method is not virtual, hence, naturally the
* function table of base shows that the method overriding stops at base method).
* 
* I'm going to make a lot of mistakes. until I finally learn these delicacies.
*/
#include <iostream>
using namespace std;
class Base {
public:
	void f(int x) { cout << "Base class method" << endl; }
};

class Derived : public Base {
public:
	void f(double y) { cout << "Derived class method" << endl; }
};

class AnotherDerived : public Base {

};

void calling_methods_of_same_name_from_derived_class() {
	Derived d{};
	d.f(int{});
	d.f(1.1);	// Only one such name in the scope

	// When the function does hide the method of base class, it is present.
	AnotherDerived dervied{};
	dervied.f(int{});

	Base b = d;
	b.f(int{});	

}

