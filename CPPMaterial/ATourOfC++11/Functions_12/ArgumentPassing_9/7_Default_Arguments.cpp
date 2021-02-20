/**
* The default argument comes with an equal sign right after the argument name.
* Default arguments can only be supplied for trailing values, naturally.
*/

class Complex {
	double re;
	double imag;
public:
	Complex(double re = {}, double imag = {}): re(re), imag(imag){}
};

/**
* The default argument is evaluated at run-time, and not at compile time. Don't use defaults that
* change, because they'd be context dependent.
*/
class WithDefault {
public:
	static int x;
public:
	WithDefault(int x = x) {}
};

int WithDefault::x = 10;
void showing_that_default_is_calculated_at_runtime() {
	WithDefault a{};	// Calls with 10.
	WithDefault::x = 20;
	WithDefault a1{};	// Calls with 20.

}

/**
* Can a function be overloaded with optional? Nope, because the call would be ambiguous if it were
* with only one argument
*/