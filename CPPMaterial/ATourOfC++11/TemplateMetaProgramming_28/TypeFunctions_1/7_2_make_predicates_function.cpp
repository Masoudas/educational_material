/**
* We can easily convert predicates into actual functions, by noting that we can define a constexpr function that returns
* the result of the predicate bool. The example below is a demonstration of this fact. Although we should point out that 
* as of C++14, we both have a _v for such types, and an actual function like implementation like we do below in the 
* standard. As such, we can call  Is_pod(), exactly like a function.
* 
* Note however that when it comes to using these notions in templates, meaning pass values to templates by calling a 
* function inside the template we can't! Because, as we may famously recall when trying to pass pointer to functions (See 
* chapter on sepcialization), the following instantiation would be considered as a function, and not a bool:
* 
* template<bool t> struct S;
* S<Is_pod()> p;	// Error! Passing a function, and not a bool!
* 
* However, wrapping it in another paranthesis solves the problem:
* S<(Is_pod()> p;	// Ok!
* 
*/
#include <type_traits>

template<typename T>
constexpr bool Is_pod() {
	return std::is_pod<T>::value;
}
