/**
* Me: Naturally, conversion is undefined from int to float or vice versa if either can't contain the value.
* Moreover, we see that floats can be used as bools as well, though we really shouldn't do that.
* 
* A prvalue of floating-point type can be converted to a prvalue of any integer type. The fractional part is 
* truncated, that is, the fractional part is discarded. If the value cannot fit into the destination type, the
* behavior is undefined (even when the destination type is unsigned, modulo arithmetic does not apply). If the 
* destination type is bool, this is a boolean conversion (see below).
* 
* A prvalue of integer or unscoped enumeration type can be converted to a prvalue of any floating-point type. 
* If the value cannot be represented correctly, it is implementation defined whether the closest higher or 
* the closest lower representable value will be selected, although if IEEE arithmetic is supported, rounding 
* defaults to nearest. If the value cannot fit into the destination type, the behavior is undefined. If the 
* source type is bool, the value false is converted to zero, and the value true is converted to one.
*/
#include <numeric>

void some_float_conversions() {
	float f = std::numeric_limits<long long>::max();	// Possibly undefined conversion.

	if (f) { // Ok, but don't do it!
		//
	}
}