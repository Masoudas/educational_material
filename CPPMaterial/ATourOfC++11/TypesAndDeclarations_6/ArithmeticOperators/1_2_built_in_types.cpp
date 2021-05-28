/**
* Me: So floats are the commanders, and everything is converted to them. Otherwise, everything including char
* types are converted to ints.
* 
* Me: When two operands of same signedness are added, the higher rank is chosen.
* Me: Then, if unsigned type can represent all values, then that one is chosen (so unsigned has higher 
* priority).
* Me: Then, if signed can represent, that one is chosen (so signed has less priority)
* Me: Then, both are promoted to the unsigned of the signed (only case where promotion takes place.)
* 
* Now, considering other built-in types:
* 
*	-	Otherwise, if either operand is long double, the other operand is converted to long double
*	-	Otherwise, if either operand is double, the other operand is converted to double
*	-	Otherwise, if either operand is float, the other operand is converted to float
*	-	Otherwise, the operand has integer type (because bool, char, char8_t, char16_t, char32_t, wchar_t, 
*		and unscoped enumeration were promoted at this point) and integral conversions are applied to produce 
*		the common type, as follows:
*		-	If both operands are signed or both are unsigned, the operand with lesser conversion rank is 
*			converted to the operand with the greater integer conversion rank
*		-	Otherwise, if the unsigned operand's conversion rank is greater or equal to the conversion rank 
*			of the signed operand, the signed operand is converted to the unsigned operand's type.
*		-	Otherwise, if the signed operand's type can represent all values of the unsigned operand, the 
*			unsigned operand is converted to the signed operand's type
*		-	Otherwise, both operands are converted to the unsigned counterpart of the signed operand's type.
* 
*	The conversion rank above increases in order bool, signed char, short, int, long, long long. The rank of 
*	any unsigned type is equal to the rank of the corresponding signed type. The rank of char is equal to the 
*	rank of signed char and unsigned char. The ranks of char8_t, char16_t, char32_t, and wchar_t are equal to 
*	the ranks of their underlying types.
* 
*/

// Recall that in MSVC int = 4, long = 4 and ulong is 8!
void promotion_rules_in_MSVC() {
	auto s = 12;
	auto u = 12u;
	auto l = 12l;
	auto ul = 12ul;
	auto ll = 12ll;

	auto u_p_l = u + l;	// This unsigned long, or equivalently unsigned int (unsigned has higher priority)
????
}