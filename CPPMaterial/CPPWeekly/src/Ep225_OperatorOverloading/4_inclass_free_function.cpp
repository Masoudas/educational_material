/**
* The minor flaws in the previous two approaches lead us to the third approach. If we declare the
* free standing operator a friend inside the class, it will have access to the internal fields of the
* class, and at the same time, we can write z = 2 + x.
* 
* Are there any flaws associated with this method?
*/

class complex {
	double re;
	double imag;

public:
	complex(double re) : re{ re }, imag{ 0 }{}
	complex(double re, double imag) : re{ re }, imag{ imag }{}

	[[nodiscard]] friend complex operator+(const complex& left, const complex& right) {
		return {left.re + right.re, right.imag + right.imag};
	}
};

void using_inclass_free_plus_operator() {
	complex c{ 1, 2 };

	complex z = 2 + c;
}
