/**
* C++ does not have covariance or contravariance when it comes to function objects. The return type and the 
* argument list must exactly match.
*/

class A{}; class B : public A {};

int function_must_completely_math_for_fptr(int x){
	int (*f)(int) = function_must_completely_math_for_fptr;
	// void (*f)(int) = function_must_completely_math_for_fptr; Return type does not match.
	return {};
}

B no_covariance_or_contravariance(A a) {
	B(*f)(A) = no_covariance_or_contravariance;
	// A(*f)(A) = no_covariance_or_contravariance; no contravariance
	// B(*g)(B a) = no_covariance_or_contravariance; No covariance 

	return {};
}