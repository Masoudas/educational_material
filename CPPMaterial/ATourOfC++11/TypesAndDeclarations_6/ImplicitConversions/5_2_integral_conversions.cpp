/**
* Me: Always recall that unsigned x = -1 is the greatest unsigned int, and that signed x = MAX_UNSIGNED_INT used to be
* undefined, but now is again module 2^n.
* 
* A prvalue of an integer type or of an unscoped enumeration type can be converted to any other integer type. 
* If the conversion is listed under integral promotions, it is a promotion and not a conversion.
*
*	-	If the destination type is unsigned, the resulting value is the smallest unsigned value equal to the 
*		source value modulo 2^n, where n is the number of bits used to represent the destination type.
*		That is, depending on whether the destination type is wider or narrower, signed integers are 
*		sign-extended or truncated and unsigned integers are zero-extended or truncated respectively.
*	-	If the destination type is signed, the value does not change if the source integer can be represented 
*		in the destination type. Otherwise [the result is implementation-defined (until C++20)] the unique 
*		value of the destination type equal to the source value modulo 2^n, where n is the number of bits used 
*		to represent the destination type. (since C++20). (Note that this is different from signed integer 
*		arithmetic overflow, which is undefined).
*	-	If the source type is bool, the value false is converted to zero and the value true is converted to 
*		the value one of the destination type (note that if the destination type is int, this is an integer 
*		promotion, not an integer conversion).
*	-	If the destination type is bool, this is a boolean conversion (discussed next).
* 
* Me: Don't confuse assignment rules with arithmetic rules. Arithmetic rules apply to 5 + 2. But this about saying what
* happens when we say short x = 2 + 5;
*/

//Me:
void conversion_among_lower_signed_and_higher_unsigned() {
	unsigned u = -12;	// -12 % 2^32 = A very large number! 
	unsigned l = 12l;	// Module 2^32 is set here (first rule.)

	signed s = 12u;	// Fine. No conversion

	int v = true;	// Promoted to int as 1.
	int x = false;	// int as 0.

	constexpr signed char sc = -255;	// Again -255 % 2^8
	static_assert(sc != -255 % 256, "Nope");	// Verfies the above!

	auto ll = 128ll;
	unsigned u2 = ll;	// Again, note that ll%2^32 is assigned here.
}