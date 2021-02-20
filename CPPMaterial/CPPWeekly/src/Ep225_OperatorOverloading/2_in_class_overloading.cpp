/**
* Imagine the complex class below. Now, we can overload the + inside the class, and it's fine.
* There's however one problem. I can say x = y + 2, where x and y are complex numbers, because
* 2 can be implicitly converted to a complex number, thus used inside the plus operator. (And note
* that with this strategy, we needn't overload the plus operator for integer!!).
* 
* However, note that we can't say x = 2 + y. Why? Because 2 has to be on the other side for the expression
* x.operator(y) to be correct. Hence, it's not a good idea to overload the plus operator inside the
* class.
*/

class complex {
	double re;
	double imag;

public:
	complex(double re) : re{re}, imag{0}{}
	complex(double re, double imag) : re{ re }, imag{ imag }{}

	complex operator+(const complex& other) {
		return complex{re + other.re, imag + other.imag};
	}
};

void using_complex_plus() {
	complex c{ 1, 2 };

	complex z = c + 2;	// Correct, especially given that we have const complex ref.
	// complex z = 2 + x; // Error. Not possible the other way around.

}