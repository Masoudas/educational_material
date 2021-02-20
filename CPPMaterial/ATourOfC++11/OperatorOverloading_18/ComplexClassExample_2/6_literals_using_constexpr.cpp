/**
* As we already know, we can use constexpr operators to come very close to the notion of literals for custom types. 
* Having a constexpr constructor for type guarantees initialization an compile type.
* 
* When constructors are simple and inline, and especially when they are constexpr, it is quite reasonable to think of 
* constructor invocations with literal arguments as literals (Don't forget that constexpr constructors have to have no
* body).
* 
* An alternative to this approach is to use the quotation mark operator, which allows conversion from a literal to a 
* custom type. Note the definition of the quotation mark operator, particularly use of the letter i. One thing that is odd
* about this operator is that it does not accept double as operator. I have to use long double for some unGodly reason. 
* Moreover, note that for the notion 1+2i to work, I need to overload the operator+. Indeed, no magic takes place here.
* 
* This user-defined literal gives us one advantage over what we get from constexpr constructors: we can use user-defined 
* literals in the middle of expressions where the {} notation can only be used when qualified by a type name.
* 
*/

class complex_l {
	double re;
	double imag;
public:
	constexpr complex_l(double r=0, double im=0) : re{ r }, imag{im}{}
};

complex_l operator+(complex_l c1, complex_l c2) {
	return complex_l{0,0};
}

constexpr complex_l operator "" i(long double d) {
	return complex_l{ 0, double(d) };
}

void construct_from_a_literal() {
	complex_l c { 1.0 + 2.0i };	// This baby uses the operator+ here. No magic occurs!
}