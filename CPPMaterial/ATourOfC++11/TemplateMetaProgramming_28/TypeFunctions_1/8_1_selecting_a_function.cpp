/**
* A function object is an object of some type, so the techniques for selecting types and values can be used to select a 
* function.
* 
* Note: As we may recall, function objects are also called "functors."
* 
* As the following example demonstrates, we can use a conditional metaprogram to choose from among function objects, and
* possibly execute them, inside a function (or a class for that matter.)
* 
* Classes with member functions computing some value are the most general and flexible mechanism for computation in 
* template metaprogramming.
* 
* Conditional is a mechanism for compile-time programming. In particular, this means that the condition must be a constant 
* expression.
*/
#include <iostream>
#include <type_traits>

using std::cout;
using std::conditional_t;
using std::is_polymorphic_v;

struct X { // write X
	void operator()(int x) { cout <<"X" << x << "!"; }
	// ...
};
struct Y { // write Y
	void operator()(int y) { cout <<"Y" << y << "!"; }
	// ...
};

void selecting_between_functions()
{
	conditional_t<(sizeof(int)>4),X,Y>{}(7); // make an X or a Y and call it
	
	using Z = conditional_t<is_polymorphic_v<X>, X, Y>;

	Z zz; // make an X or a Y
	zz(7); // call an X or a Y
}