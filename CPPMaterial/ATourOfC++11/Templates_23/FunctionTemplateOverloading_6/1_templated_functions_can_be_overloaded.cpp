/**
* A templated function can be overloaded, with different templates, or even the same template that
* is distinctly different.
* 
* When an overloaded function is called, overload resolution is necessary to find the right function 
* or function template to invoke.
* 
* In the same way that a function template is a generalization of the notion of a function, the rules for 
* resolution in the presence of function templates are generalizations of the function overload resolution rules. 
* Basically, for each template we find the specialization that is best for the set of function
* arguments. Then, we apply the usual function overload resolution rules to these specializations and
* all ordinary function.
* 
* Me: In conclusion:
* 1- First pick the best suited templated function (resolution maybe complete here, or not like the example below).
* 2- Now, resolve, like dealing with an ordinary function.
* 
* To further elaborate, Bjarne says:
* [1]	Find the set of function template specializations (§23.2.2) that will take part in overload 
*	resolution. Do this by considering each function template and deciding which template
*	arguments, if any, would be used if no other function templates or functions of the same
*	name were in scope. For the call sqrt(z), this makes sqrt<double>(complex<double>) and
*	sqrt<complex<double>>(complex<double>) candidates.
* 
* [2]	If two function templates can be called and one is more specialized than the other
*	consider only the most specialized template function in the following steps.
*	For the call sqrt(z), this means that sqrt<double>(complex<double>) is preferred over
*	sqrt<complex<double>>(complex<double>): any call that matches sqrt<T>(complex<T>) also 
*	matches sqrt<T>(T) (Me: what do we mean by more specialized here?)
* 
* [3]	Do overload resolution for this set of functions, plus any ordinary functions, 
*	as for ordinary functions (§12.3). If a function template’s argument has been determined by 
*	template argument deduction (§23.5.2), that argument cannot also have promotions, standard
*	conversions, or user-defined conversions applied. For sqrt(2), sqrt<int>(int) is an exact
*	match, so it is preferred over sqrt(double).
* 
* [4]	If a function and a specialization are equally good matches, the function is preferred.
*	Consequently, sqrt(double) is preferred over sqrt<double>(double) for sqrt(2.0)
* 
* [5]	If no match is found, the call is an error. If we end up with two or more equally good
*	matches, the call is ambiguous and is an error.
*/
#include <complex>

template<typename T>
T sqrt1(T t) { return T{}; }

template<typename T>
std::complex<T> sqrt1(std::complex<T> t) { return std::complex<T>{}; }

double sqrt1(double) { return {}; };

void using_overloaded_sqrts(std::complex<double> z)
{
	sqrt1(2); // sqrt<int>(int)
	sqrt1(2.0); // sqrt(double)
	sqrt1(z); // sqrt<double>(complex<double>) 
}