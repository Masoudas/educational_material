/**
* A type function can have multiple arguments. For example:
* 

template<typename T, int N>
struct Array_type {
	using type = T;
	static const int dim = N;
};

* This Array_type is not a standard-library function or even a particularly useful function. We just used it as an excuse 
* to show how to write a simple multi-argument, multi-return-value type function. It can be used like this:

using Array = Array_type<int,3>;
Array::type x; // x is an int
constexpr int s = Array::dim; // s is 3

* me: Hence, as the big guy says, a type function can have multiple arguments and multiple return values.
* 
* Note that type functions are compile-time functions. That is, they can only take arguments (types and values) that are 
* known at compile time and produce results (types and values) that can be used at compile time.
*/

