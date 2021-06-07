/**
* Me: An easy way to recall overflow rules is that -1 always becomes INT_MAX for unsigned.
* 
* Unsigned integer arithmetic is always performed modulo 2^n where n is the number of bits in that particular integer. E.g. 
* for unsigned int, adding one to UINT_MAX gives ​0​, and subtracting one from ​0​ gives UINT_MAX.
*
* When signed integer arithmetic operation overflows (the result does not fit in the result type), the behavior is 
* undefined, 
*
* The possible manifestations of such an operation include:
*	-	it wraps around according to the rules of the representation (typically 2's complement),
*	-	it traps - on some platforms or due to compiler options (e.g. -ftrapv in GCC and Clang),
*	-	it saturates to minimal or maximal value (on many DSPs),
*	-	it is completely optimized out by the compiler
*/