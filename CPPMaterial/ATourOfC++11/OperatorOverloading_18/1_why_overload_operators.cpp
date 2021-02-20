/**
* Having shorthand representation for operations is important and good.
* 
* Like most languages, C++ supports a set of operators for its built-in types. However, most concepts 
* for which operators are conventionally used are not built-in types in C++, so they must be represented as 
* user-defined types. For example, if you need complex arithmetic, matrix algebra, logic signals, or character 
* strings in C++, you use classes to represent these notions.  Defining operators for such classes sometimes 
* allows a programmer to provide a more conventional and convenient notation for manipulating objects than 
* could be achieved using only the basic functional notation.
* 
* For example, if b and c are complex types, b + c now means b.operator+(c);
*/

class complex { // very simplified complex
	double re, im;
public:
	complex(double r, double i) :re{ r }, im{ i } { }
	complex operator+(complex) {
		return { 1,1 };
	};
	complex operator*(complex) {
		return { 1,1 };
	};
};
