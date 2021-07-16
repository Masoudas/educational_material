/**
 * Me: Notice that there's no boolean equivalent in C, which is something I had forgotten about since 2009 I 
 * guess!
 * 
 * There are only a few basic data types in C:
 *	char:	a single byte, capable of holding one character in the local character set	
 *	int:	an integer, typically reflecting the natural size of integers on the host machine 
 *	float:	single-precision floating point
 *	double: double-precision floating point
 *
 * There then combinations of some of these types with the words short or long:
 * 	short int;
 *  long double;
 * Note that the word int can be omitted, but not double in the second example.
 * 
 * The intent is that short and long should provide different lengths of integers where practical; int will 
 * normally be the natural size for a particular machine. short is often 16 bits long, and int either 16 or 32 
 * bits. Each compiler is free to choose appropriate sizes for its own hardware, subject only to the the 
 * restriction that short s and int s are at least 16 bits, long s are at least 32 bits, and short is no longer 
 * than int , which is no longer than long (me: C++ rules thus apply here).
 * 
 * The qualifier signed or unsigned may be applied to char or any integer. unsigned numbers are always positive 
 * or zero, and obey the laws of arithmetic modulo 2^n , where n is the number of bits in the type. So, for 
 * instance, if char s are 8 bits, unsigned char variables have values between 0 and 255, while signed chars have 
 * values between -128 and 127 (in a two’s complement). Whether plain char s are signed or unsigned is machine-dependent, 
 * but printable characters are always positive.
 * 
 * The type long double specifies extended-precision floating point. As with integers, the sizes of floating-point objects 
 * are implementation-defined; float , double and long double could represent one, two or three distinct sizes.
 * 
 * The standard headers <limits.h> and <float.h> contain symbolic constants for all of these sizes, along with other
 * properties of the machine and compiler (limits for integral types and float for floating point types.)
 */

