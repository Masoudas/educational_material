/**
* The big guy says "I prefer to minimize the number of functions that directly manipulate the representation of an
* object. This can be achieved by defining only operators that inherently modify the value of their
* first argument, such as +=, in the class itself.  Operators that simply produce a new value based on the values of their
* arguments, such as +, are then defined outside the class and use the essential operators in their implementation".
* 
* This is a very good and natural argument by the big guy. Although I find the notion of defining friend operators quite
* appealing as well, as they provide access the private parts of the class. 
* 
* Note that in the following example, the arguments to the operator+() are passed by value, so a+b does not modify its 
* operands. Also notice how the construction of a complex object works now, that is, we can write 
* 'complex r1 {x+y+z}; // r1 = operator+(operator+(x,y),z)'
* Except for possible efficiency differences, the computations of r1 and r2 are equivalent.
* 
* Note that += and *= types are generally more efficient, because they require less variables. Hence, they're perfect for
* alignment.
*/

class complex {
	double re, im;
public:
	complex& operator+=(complex a) { return *this; }; // needs access to representation
	// ...
};

complex operator+(complex a, complex b)
{
	return a += b; // access representation through +=
}

void using_the_complex_overloaded_operators(complex x, complex y, complex z) {
	complex r1{ x + y + z }; // r1 = operator+(operator+(x,y),z)
	complex r2{ x }; // r2 = x
	r2 += y; // r2.operator+=(y)
	r2 += z; // r2.operator+=(z)
}