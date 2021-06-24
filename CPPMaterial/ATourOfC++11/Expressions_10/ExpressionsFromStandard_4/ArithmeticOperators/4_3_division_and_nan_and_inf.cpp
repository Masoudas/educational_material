/**
* The binary operator / divides the first operand by the second (after usual arithmetic conversions).
* For integral operands, it yields the algebraic quotient.
* 
* -	The quotient is rounded in implementation-defined direction. (until C++11)
* - The quotient is truncated towards zero (fractional part is discarded). (since C++11)
* 
* If the second operand is zero, the behavior is undefined, except that if floating-point division is taking 
* place and the type supports IEEE floating-point arithmetic (see std::numeric_limits::is_iec559), then:
*	-	if one operand is NaN, the result is NaN
*	-	dividing a non-zero number by ±0.0 gives the correctly-signed infinity and FE_DIVBYZERO is raised
*	-	dividing 0.0 by 0.0 gives NaN and FE_INVALID is raised
*/

#include <numeric>

void division_by_zero() {
	// constexpr auto int_division = 10 / 0; Compile-time error! Division by zero
	if constexpr (std::numeric_limits<float>::is_iec559) {
		// constexpr auto divide_by_zero = 1. / 0.0;	Compile-time error! At run-time sets to inf. Don't
														// forget the 0.0, otherwise this would be an int
														// division.
		constexpr double number_by_zero = 0.0 / std::numeric_limits<float>::infinity();	// Zero!
		constexpr double number_by_nan = 0.0 / std::numeric_limits<float>::signaling_NaN(); // Nan!


	}
}