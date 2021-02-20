/**
* Now the second idea is to overload the + operator as a free standing function. This strategy
* solves the z = 2 + x problem mentioned in 2. The problem however is that the free standing operator
* does not have access to the private members of the complex class. Granted, we can solve this by declaring
* the operator a friend function, or have accessor functions, but still, we could consider this a problem.
* 
* The other issue in my humble opinion is that a free standing function violates encapsulation. We normally
* expect the operator working on a class to be inside that class. Although I'm sure that his highness, Mr. Bjarne,
* would argue that "would you say that encapsulation has been violated if another class uses this class"?
*/

class complex {
	double re;
	double imag;

public:
	complex(double re) : re{ re }, imag{ 0 }{}
	complex(double re, double imag) : re{ re }, imag{ imag }{}

	complex operator+(const complex& other) {
		return complex{ re + other.re, imag + other.imag };
	}
};

//complex operator+(const complex& left, const complex& right) {
	// return complex{left.re + right.re, left.imag + right.imag}; Error! No access to private elements.
//}