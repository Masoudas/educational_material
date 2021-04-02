/**
* Me: Perhaps the following discussion was important in C++11 for some reason. It does appear that there's no problem
* with modern compilers, because even before compilation, we can quickly see the type.
* 
* There is one case in which it is significant to use ::type directly, rather than an alias. If only one of the 
* alternatives is supposed to be a valid type, we should not use an alias. Consider first a simple analogy:

if (p){
	*p = 7;
}

* It is important that we don’t enter the block if p is the nullptr. We are using the test to see if p is valid. Similarly, 
* we might want to test to see if a type is valid. For example:

conditional<std::is_integral<T>::value, std::make_unsigned<T>, Error<T>>::type

* where we used two type functions is_integral and make_unsigned. If this fails, then we have to deal with the Error 
* indicator. Now, had we defined an alias for this situation:

typename make_unsigned<T>::type

* and tried to use it for a nonintegral type, say std::string, we would have tried to make a nonexistent type 
* (make_unsigned<std::string>::type). The result would have been a compile-time error.
*/
#include <type_traits>
template<typename T>
struct error{};
void creating_wrong_unsigned_type() {
	std::conditional<std::is_integral_v<double>, std::make_unsigned<double>, error<double>>::type t;	// T is now
																										// error double
	std::conditional<std::is_integral_v<int>, std::make_unsigned<int>, error<double>>::type t1;	// T is now make_unsigned.
}