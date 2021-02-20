/**
* Functions on the other hand can be both templated and non-templated. This is because the compiler is responsible
* for deduction of the type of functions, and there's overloading rules regarding functions. Hence, the compiler
* can choose which version of the function to choose based on the given rules, or throw an error, which is not
* the case for types.
* 
*/
#include <iostream>

template<typename T>
void can_be_both_templated_and_non_templated() {
	std::cout << "Inside non-templated function\n";
}

void can_be_both_templated_and_non_templated() {
	std::cout << "Inside templated function\n";
}

//int main() {
//	can_be_both_templated_and_non_templated<int>();
//
//	can_be_both_templated_and_non_templated();
//}