/**
* To deal with cases such as 2 + z for complex numbers, we need to define an operator that allows implicit conversion
* from 2 to z. Note that it's assumed that there's no direct conversion from double or int to complex. Thus, we actually
* need to overload the operators in such case.
*/

struct complex {
	double re, im;
public:
	complex& operator+=(complex a){
		re += a.re;
		im += a.im;
		return *this;
	}

	complex& operator+=(double a){
		re += a;
		return *this;
	}

	double real() { return re; }
	double imag() { return im; }
};

complex operator+(complex a, complex b){
	return a += b; // calls complex::operator+=(complex)
}
complex operator+(complex a, double b){
	return { a.real() + b,a.imag() };
}
complex operator+(double a, complex b){
	return { a + b.real(),b.imag() };
}

void adding_doubles_to_complexes(complex x, complex y){
	auto r1 = x + y; // calls operator+(complex,complex)
	auto r2 = x + 2; // calls operator+(complex,double)
	auto r3 = 2 + x; // calls operator+(double,complex)
	auto r4 = 2 + 3; // built-in integer addition
}
