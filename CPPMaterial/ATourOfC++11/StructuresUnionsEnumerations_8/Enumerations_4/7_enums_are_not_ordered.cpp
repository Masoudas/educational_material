/**
* While reading concepts in templates in chapter 24, I came accross this enum class 'enum class rps{rock, paper, 
* scissor}', which motivated me to point out enums are not ordered!
* 
* Note that in C++, we can compare enums for equality, and as such, there's an operator defined for comparison by
* default, which compares the integral value behind enums (hence, there's an implicit conversion to int that takes
* place.) However, enums are considered unordered, and we better define an order for them as independent operators.
* Why? For one thing, we can repeat a value in enums, like the example shown below. Hence, don't depend on the
* natural order of enums, and at least the big guy does not consider them ordered.
* 
* For example below, we consider rock < paper, however, we get equal here. I get that the enum is still orderable,
* but it's not what we expect. Therefore, don't rely on the natural order, and always define your own order!
* 
* An overloaded operator is shown below.
*/
#include <iostream>

enum class rps { rock = 0, scissors = 0, paper = 0 };

//int main() {
//	if (rps::rock < rps::paper) {
//		std::cout << "rock is less than paper";
//	}
//	else {
//		std::cout << "rock is NOT less than paper!";
//
//	}
//}


//bool operator<(const rps& lhs, const rps& rhs) {
//	// using enum rps; For dragging the enum scope here.
//	// Note that we can't use switch case, because we have repated labels, and enums are implicitly converted to
//	// ints.
//	if (lhs == rps::rock) {
//		return false;
//	}
//	else if (lhs == rps::paper){
//		if (rhs == rps::rock || rhs == rps::paper) return false;	// Wiggly is for redundant code, because both	
//																	// enums evaluate to zero, and we're rechecking!
//		return true;
//	}
//}