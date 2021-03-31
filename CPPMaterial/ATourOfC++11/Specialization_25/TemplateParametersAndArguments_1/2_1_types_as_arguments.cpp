/**
* A template argument is defined to be a type, if it's preceded with the typename or class keyword (me: our 
* usuall perception of template definition.)
* 
* A type argument is unconstrained; that is, there is nothing in the interface of a class that constrains it to 
* be a certain kind of type or part of a class hierarchy. The validity of an argument type depends exclusively  
* on its use in the templates, providing a form of duck typing (if it walks like a duck, and it quacks like a 
* duck, it's a duck.)
* 
* User-defined and built-in types are handled equivalently when used as template arguments. This is essential for 
* allowing us to define templates that work identically for user-defined and built-in types. In particular, there 
* is no space or time overhead implied by using either compared to the other:
*	- Values of built-in types are not "boxed" into special container objects (unlike C# or Java).
*	- Values of all types are retrieved directly from a vector without use of potentially expensive 
*	  (e.g., virtual) "get() functions."
*	- Values of user-defined types are not implicitly accessed through references.
* Me: I'm not sure what this last one implies. Particularly with functions, if we try to pass lvalues (for
* example objects,) then the template type is deduced as reference, to avoid a new copy. Other than that, I
* guess perhaps what he's implying is that a supplied templated type (like in a class) is copied, unless we
* specify passing by reference.)
* 
*/
#include <complex>
template<typename T>
void f_templated(T t) { };

template<typename T>
class X {};

void using_function_templates() {
	f_templated(1); // T deduced to be int
	f_templated<double>(1); // T is double
	f_templated<std::complex<double>>(1); // T is complex<double>

	// Me:
	double x{5};
	f_templated(x);	// Template type is double&, and double.
}

// Recall that there's no type deduction for a class template, to allow for templated class constructors.
void using_templated_class() {
	X<double> x1; // T is double
	X<std::complex<double>> x2; // T is complex<double>
}
