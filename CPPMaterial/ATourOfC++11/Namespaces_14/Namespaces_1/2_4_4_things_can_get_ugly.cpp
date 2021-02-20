/**
* Take a look at the following scenario and be very mindful about signature design and function
* naming in various namespaces.
* 
* One major difference between namespaces and classes is that the search for a declaration of a 
* function f() does not have a preference for functions in a namespace in which f() is called 
* (the way it does for functions in a class in which f() is called).
*/

namespace N {
	template<class T>
	void f(T, int) {}; // N::f()
	class X { };
}
namespace N2 {
	N::X x;
	void f(N::X, unsigned) {};
	void g()
	{
		f(x, 1); // calls N::f(X,int), because 1 is an integer literal.
	}
}