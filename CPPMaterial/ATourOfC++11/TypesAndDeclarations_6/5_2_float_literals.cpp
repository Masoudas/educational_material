/**
* Me: So as we shall see, we can represent floats in hexadecimal as well. We should also note that we start
* from double and go up. There's no float literal first, unless explicity specified. 
* 
*	-	digit-sequence decimal-exponent suffix(optional)	(1)	
*	-	digit-sequence . decimal-exponent(optional) suffix(optional)	(2)	
*	-	digit-sequence(optional) . digit-sequence decimal-exponent(optional) suffix(optional)	(3)	
*	-	0x | 0X hex-digit-sequence hex-exponent suffix(optional)	(4)	(since C++17)
*	-	0x | 0X hex-digit-sequence . hex-exponent suffix(optional)	(5)	(since C++17)
*	-	0x | 0X hex-digit-sequence(optional) . hex-digit-sequence hex-exponent suffix(optional)	(6)	
*		(since C++17)
* 
*	(1) digit-sequence representing a whole number without a decimal separator, in this case the exponent is 
*		not optional: 1e10, 1e-5L
*	(2) digit-sequence representing a whole number with a decimal separator, in this case the exponent is 
*	optional: 1., 1.e-2
*	(3) digit-sequence representing a fractional number. The exponent is optional: 3.14, .1f, 0.1e-1L
*	(4) Hexadecimal digit-sequence representing a whole number without a radix separator. The exponent is 
*	never optional for hexadecimal floating-point literals: 0x1ffp10, 0X0p-1
*	(5) Hexadecimal digit-sequence representing a whole number with a radix separator. The exponent is never 
*	optional for hexadecimal floating-point literals: 0x1.p0, 0xf.p-1
*	(6) Hexadecimal digit-sequence representing a fractional number with a radix separator. The exponent is 
*	never optional for hexadecimal floating-point literals: 0x0.123p-1, 0xa.bp10l
* 
* suffix, if present, is one of f, F, l, or L. The suffix determines the type of the floating-point literal:
*	-	(no suffix) defines double
*	-	f F defines float
*	-	l L defines long double
*
* Optional single quotes (') can be inserted between the digits as a separator, they are ignored when compiling.
*/