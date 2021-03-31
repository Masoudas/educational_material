/**
* Me: The big guy uses std::remove_reference to illustrate the need for decay. However, as we now know, 
* removing cv qualifiers is half of what decay does. But his example conveys the important point we discussed
* before. That is, particularly with templates, we sometimes deduce with l-value reference to avoid copies,
* and decay removes that for us.
* 
* The big guy says:
* 
* "The decay functions handles array decay as well as reference dereferencing.
* The type functions for adding and removing references are important for when writing templates that should 
* work with an argument that may be reference or not. For example."
* 
* Note: The example unfortunately is wrong. Because the big guy has forgotten to use lvalue or lvalue references
* in the function argument. Therefore, this example does not work as intended, and in fact, we always get copies
* of the variables. He should have written F&& in the function argument.
*/
#include <type_traits>
#include <iostream>

template<typename T>
void f(T v)
{
	std::remove_reference_t<T> x = v; // copy of v
	T y = v; // maybe copy of v; maybe a reference to v!	(Me: Nope! Always is T, and not T&)
	++x; // increment local variable
	++y;
	std::cout << std::is_reference_v<T>;
	// ...
}

void user(int val = 7)
{
	// Here, x really is a copy of v, but if T is a reference type, y is a reference to v :
	f(val); // call f<int&>(): the ++y in f() will increment val (Me: Nope. Because function gets T and neither 
			// T& nor T&&. Sorry big guy!)													
	f(7); // call f<int>(): the ++y in f will increment a local copy
}

