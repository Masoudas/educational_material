/**
* One obvious use of One obvious use of namespaces is to wrap a complete set of declarations and 
* definitions in a separate namespace.
* 
* The list of declarations will, in general, contain namespaces. Thus, nested namespaces are allowed. 
* This is allowed for practical reasons, as well as for the simple reason that constructs ought to nest 
* unless there is a strong reason for them not to.
* 
* The usual scope rules apply. (Me: A function or a loop scope is an example of nested scope normally).
*/

void h();
namespace X {
	void g();
	// ...
	namespace Y {
		void f();
		void ff();
		// ...
	}
}