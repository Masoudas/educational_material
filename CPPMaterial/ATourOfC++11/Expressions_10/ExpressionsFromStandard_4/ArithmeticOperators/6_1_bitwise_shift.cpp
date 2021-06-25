/** 
* Me: Essentially, the only undefined behavior until C++20 was left shift of negative number, which does make
* sense. Right shift of signed is implementation defined (!) but mostly keeps the sign as observed. From C++20,
* bit shift essentially throws away bits from left or right, so it's very straightforward. As is the case in
* embedded programming, we want to use shifts with unsiged types, or possibly positive values for signed types,
* and almost never with signed types (as of C++20, feel free to use it in both cases.)
* 
* Me: An interesting case is shifting 1 left to bit 31 for a signed 32 bit. In this case, the resulting value
* is INT_MIN, because 1 << 31 is representable in the unsigned version of 32 bit. Hence, this value is converted
* to 32 signed (-1). However, 1<<32 is undefined because shift exceeds number of bits (or can't be put in
* sunsigned equivalent.)
* 
* 
* The bitwise shift operator expressions have the form
*	-	lhs << rhs	(1)	
*	-	lhs >> rhs	(2)	
*	1) left shift of lhs by rhs bits
*	2) right shift of lhs by rhs bits
* For the built-in operators, lhs and rhs must both have integral or unscoped enumeration type. Integral 
* promotions are performed on both operands.
*
* Me: Recall that for enums, conversion to the underlying type takes place, with promotion to uint32 for 
* smaller types.
* 
* The return type is the type of the left operand after integral promotions.
* 
* --------------------------------------------------------------------------------------------------------
* Unitl C++20:
* For unsigned a, the value of a << b is the value of a * 2b, reduced modulo 2N, where N is the number of bits 
* in the return type (that is, bitwise left shift is performed and the bits that get shifted out of the 
* destination type are discarded).
*
* For signed and non-negative a, if a * 2b is representable in the unsigned version of the return type, then 
* that value, converted to signed, is the value of a << b (this makes it legal to create INT_MIN as 1<<31); 
* otherwise the behavior is undefined.
* 
* For negative a, the behavior of a << b is undefined.
* For unsigned a and for signed and non-negative a, the value of a >> b is the integer part of a/2b
* For negative a, the value of a >> b is implementation-defined (in most implementations, this performs 
* arithmetic right shift, so that the result remains negative).
*
* From C++20:
* The value of a << b is the unique value congruent to a * 2b modulo 2N, where N is the number of bits in the 
* return type (that is, bitwise left shift is performed and the bits that get shifted out of the destination 
* type are discarded).
* 
* The value of a >> b is a/2b, rounded down (in other words, right shift on signed a is arithmetic right shift).
* -------------------------------------------------------------------------------------------------------
* In any case, if the value of the right operand is negative or is greater or equal to the number of bits in 
* the promoted left operand, the behavior is undefined (Me: I can shift a uint8_t 12 times one by one, but can't
* shift it once twelve times (a << 12)).
*/

#include <iostream>
enum { ONE = 1, TWO = 2 };

/** Prints:

0x123 << 1 = 0x246
0x123 << 63 = 0x8000000000000000
0x10 << 10 = 0x4000
-1000 >> 1 = -500

*/
void examples_involving_shifts()
{
    std::cout << std::hex << std::showbase;
    char c = 0x10;
    unsigned long long ull = 0x123;
    std::cout << "0x123 << 1 = " << (ull << 1) << '\n'
        << "0x123 << 63 = " << (ull << 63) << '\n' // overflow in unsigned
        << "0x10 << 10 = " << (c << 10) << '\n';   // char is promoted to int
    long long ll = -1000;
    std::cout << std::dec << "-1000 >> 1 = " << (ll >> ONE) << '\n';
}