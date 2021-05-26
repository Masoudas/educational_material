/**
* A prvalue of a floating-point type can be converted to a prvalue of any other floating-point type. If the 
* conversion is listed under floating-point promotions, it is a promotion and not a conversion.
*
*	-	If the source value can be represented exactly in the destination type, it does not change.
*	-	If the source value is between two representable values of the destination type, the result is one of 
*		those two values (it is implementation-defined which one, although if IEEE arithmetic is supported, 
*		rounding defaults to nearest).
*	-	Otherwise, the behavior is undefined.
*/

void float_conversions() {
	auto d = 12.;	
	float f = d;	// Hopefully, between two acceptable values.

	auto ld = 12.l;
	d = ld;	// Again, we hope for the best.
}