/**
 * We may wonder what happens to signed and unsigned operators under shift operators.
 */

/**
 * Unsigned case: In the unsigned case, and especially shift to right, the bits are properly shifted.
 */
#include <iostream>

void unsignedShift(){
    unsigned int a1 = 0x80000000;
    unsigned int a2 = (a1 >> 1) - 0x40000000;  // A normal shift has occured here.
    unsigned int a3 = a1 << 1; // This will print zero.

    std::cout << a2 << std::endl;
    std::cout << a3 << std::endl;
}

/**
 * With signed bits, as we know, if the number is negative, when shifting to right, the sign bit is repeated. Shift to left
 * is done normally. */
void signedShift(){
    int a1 = 0x80000000;
    int a2 = a1 << 1;   // This will be zero;

    int a3 = (a1 >> 1) - 0xC0000000;

    std::cout << a2 << std::endl;
    std::cout << a3 std::endl;
}

int main(){
    unsignedShift();
    signedShift();
}