/* The binary operator * performs multiplication of its operands (after usual arithmetic conversions), except that, for U
* floating-point multiplication,
*	-	multiplication of a NaN by any number gives NaN
*	-	multiplication of infinity by zero gives NaN and FE_INVALID is raised (Me: INf by other vals is inf)
* 
*/

#include <numeric>
void multiplication_by_inf() {
	constexpr float inf = std::numeric_limits<float>::infinity();
	constexpr float minus_inf = -std::numeric_limits<float>::infinity();

	constexpr auto inf_times_inf = inf * inf;	// Result is still float, and inf.
	constexpr auto inf_times_minus_inf = inf * minus_inf;	// Minus inf and float.
}
