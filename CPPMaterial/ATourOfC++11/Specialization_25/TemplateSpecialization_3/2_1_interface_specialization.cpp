/** 
* Sometimes, a specialization is not an algorithmic optimization, but a modification of an interface 
* (or even a representation).For example, the standard library complex uses specializations to adjust the 
* set of constructors and the argument types for important operations for important specializations (such 
* as complex<float> and complex<double>).The general (primary) template looks like shown below.
* 
* Note that the scalar assignment operators take reference arguments. That’s not efficient for floats, so 
* complex<float> passes those by value.
* 
* Note that these specialized constructors are constexpr, making complex<double> a literal type. We could 
* not do that for the general complex<T>. Also, this definition takes advantage of the knowledge that 
* conversion from complex<float> to complex<double> is safe (it never narrows), so that we can have an 
* implicit constructor from complex<float>. Howev er, the constructor from complex<long double> is 
* explicit to make narrowing less likely.
*/

#include <complex>
template<typename T>
class complex {
public:
	complex(const T& re = T{}, const T& im = T{}) {};
	complex(const complex&) {}; // copy ctor uctor

	template<typename X>
	complex(const complex<X>&) {}; // conversion from complex<X> to complex<T>
	
	template<typename X>
	complex<T>& operator=(const complex<X>& x) { return complex<T>{x}; };
};

template<>
class complex<float> {
public:
	constexpr complex(float, float im = 0) {}
	complex<float>& operator=(float f) { auto x = complex<float>{ f }; return x; };
};

template<>
class complex<double> {
public:
	constexpr complex(double re = 0.0, double im = 0.0) {};
	constexpr complex(const complex<float>&) {};
	explicit constexpr complex(const complex<long double>&) {};
	// ...
};