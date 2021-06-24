/**
* The bitwise arithmetic operator expressions have the form
*	-	~ rhs		(1)	
*	-	lhs & rhs	(2)	
*	-	lhs | rhs	(3)	
*	-	lhs ^ rhs	(4)	
* 
*	1) bitwise NOT,	
*	2) bitwise AND,
*	3) bitwise OR,
*	4) bitwise XOR
* 
* For the built-in operators, lhs and rhs must both have integral or unscoped enumeration type. Usual 
* arithmetic conversions are performed on both operands and determine the type of the result.
*
* Me: Recall that for enumerations, result is a variable of the underlying type.
* 
* The result of operator~ is the bitwise NOT (one's complement) value of the argument (after promotion). The 
* result of operator& is the bitwise AND value of the operands (after usual arithmetic conversions). The 
* result of operator| is the bitwise OR value of the operands (after usual arithmetic conversions). The 
* result of operator^ is the bitwise XOR value of the operands (after usual arithmetic conversions).
* 
*/

void logic_ops_on_enums() {
	enum ch_e : char {a, b};
	enum ll_e : long long {d, e};

	auto r_ch_e = a | b;	// a and b are promoted to int, hence result is int.
	auto r_ll_e = ~d;	// Result is cast to long long, the underlying type.
}

#include <iostream>
#include <iomanip>
#include <bitset>
/**
Mask: 0xf0                                 0000000011110000
Value: 0x12345678          00010010001101000101011001111000
Setting bits: 0x123456f8   00010010001101000101011011111000
Clearing bits: 0x12345608  00010010001101000101011000001000
Selecting bits: 0x70       00000000000000000000000001110000
XOR-ing bits: 0x12345688   00010010001101000101011010001000
Inverting bits: 0xedcba987 11101101110010111010100110000111
*/
void standard_example()
{
    uint16_t mask = 0x00f0;
    uint32_t x0 = 0x12345678;
    uint32_t x1 = x0 | mask;
    uint32_t x2 = x0 & ~mask;
    uint32_t x3 = x0 & mask;
    uint32_t x4 = x0 ^ mask;
    uint32_t x5 = ~x0;
    using bin16 = std::bitset<16>;
    using bin32 = std::bitset<32>;
    std::cout << std::hex << std::showbase
        << "Mask: " << mask << std::setw(49) << bin16(mask) << '\n'
        << "Value: " << x0 << std::setw(42) << bin32(x0) << '\n'
        << "Setting bits: " << x1 << std::setw(35) << bin32(x1) << '\n'
        << "Clearing bits: " << x2 << std::setw(34) << bin32(x2) << '\n'
        << "Selecting bits: " << x3 << std::setw(39) << bin32(x3) << '\n'
        << "XOR-ing bits: " << x4 << std::setw(35) << bin32(x4) << '\n'
        << "Inverting bits: " << x5 << std::setw(33) << bin32(x5) << '\n';
}