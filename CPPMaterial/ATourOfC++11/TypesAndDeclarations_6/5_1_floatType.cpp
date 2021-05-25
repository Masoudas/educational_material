/**
 * They are an appoximation of real values. We have, float, double, long double.
 * Again, these are implementation dependent. Usually if we don't have time to study different floating 
 * points, we use double and hope for the best.
 * 
 * Floating point literals are double. Compiler should warn for ones exceeding the range.
 * For smaller than range, it does not show any warnings, and just wraps to zero.
 * 
 * The suffix f or F makes a literal floating point. The suffix l or L makes it double long.
 * 
 * As opposed to integer types, note that floating point types can't be used with logical unary operators.
 * or bitwise operations such as &, | or ^, because these are undefined. For example, we can't say ~float or 
 * float1 & float2. 
 * 
 * Me: Note however that floating points can participate in logical operations. We know that for example
 * 'float1 != float2' is acceptable (though not wise). Moreover, if(f1) or f1 && f2  are both acceptable
 * as well. (It appears that like integers, zero is considered false, and other numbers true). But don't do it. 
 * Because zero may not be zero!
 * 
 * Also note that using reinterpret_cast, we can actually convert a float type to an integer type and perform
 * bitwise operations.
 * 
 * The standard states that "Implicit conversions are defined between real floating types and integer types."
 * 
 * Me: Note also that the standard does not specify any size guarantees on float types. 
 */
#include <iostream>
void double_literal_examples() {
	float f1 = 1.23f;
	float f2 = 1.23;	// The literal is double
	float f3 = 0;

	double d1 = 1e-3;
	double d2 = 1E308;
	double d3 = 1E-4000;	// This is out of range.

	long double d4 = 1e301;

	std::cout << d2 << std::endl;

	if (f1 || (f3 && f2)) {
		std::cout << "We used a float in a conditional!!!" << std::endl;
	}
}

//int main() {
//	double_literal_examples();
//}