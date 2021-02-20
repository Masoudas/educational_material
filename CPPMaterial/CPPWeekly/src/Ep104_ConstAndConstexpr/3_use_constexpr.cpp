/**
* Now, when it comes to types that are literal, it's best practice to use constexpr. Note that in the following
* example, the constructor is not explicitly defined as constexpr. However, the default constexpr is (by default)
* a constexpr constructor.
* 
* Now, note that binding compile-time information to run-time depends on whether or not the method that does it
* is const. Why? Because if the method is going to change the compile-time information, then the type would not
* be constexpr. Once we take care of this condition, we can bind compile-time and run-time information.
*/
#include <iostream>

using std::cout;

struct Type {
	int data{};

	constexpr int do_thing() const { return data + 4; }	// Only a return statement, per C++11.
};

constexpr Type t{};

void using_constexpr_class() {
	int val = t.do_thing();	// Binding compile-time information in run-time.
	
	int val1 = t.data;	// Binding with invarianrs.
}
