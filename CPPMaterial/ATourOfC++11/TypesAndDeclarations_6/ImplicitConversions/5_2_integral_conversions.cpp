/**
* Me: I don't think these should be confused with arithmetic rules. This is because in those, we don't have a 
* destination type. These rules are for the case when we say for example unsigned x = 12;
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
* Me: In the expression 12u < 12 who determines what the destination type is? I think because 12l is potentially
* larger in range, it would be the one. Whereas in 12u < 13l, the destination type is ul (and not l apparently), 
* rather than unsigned. Note that this is not promotion by the way, because there's no promotion to long.
*/

//Me:
void conversion_among_lower_signed_and_higher_unsigned() {
	unsigned l = 12l;	// Module 2^32 is set here (first rule.)

	signed u = 12u;	// Fine. No conversion

	int v = true;	// Promoted to int as 1.
	int x = false;	// int as 0.

	constexpr signed char sc = -255;	// Again -255 % 2^8
	static_assert(sc != -255 % 256, "Nope");	// Verfies the above!

}
???https://en.cppreference.com/w/cpp/language/implicit_conversion#cite_note-1
//int main() {
//	conversion_among_lower_signed_and_higher_unsigned();
//}