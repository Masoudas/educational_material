/**
* If we wanted an integral type or a float point type to be converted to our type, we need to have the proper constructors.
* 
* A constructor is a prescription for creating a value of a given type. The constructor is used when a value of a type is 
* expected and when such a value can be created by a constructor from the value supplied as an initializer or assigned value. 
* Thus, a constructor requiring a single argument need not be called explicitly. For example complex b {3} means 
* complex b {3,0};
* 
* A user-defined conversion is implicitly applied only if it is unique. If you don’t want a constructor to be used implicitly, 
* declare it explicit.
* 
* Now, we may define single and double floating point constructors, or we can define a constructor with two optional doubles.
* Note that if we do the latter, the construction Complex c = 0; is still ok, and creates a complex type, and overload
* resolution works.
*/

class complex {
	double re, im;
public:
	complex(double r = 0, double i = 0) : re{ r }, im{ i } { }
};

void conversion_with_two_optional_params() {
	complex c1 = 5;
}


