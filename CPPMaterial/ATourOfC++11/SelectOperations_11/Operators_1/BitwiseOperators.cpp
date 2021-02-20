/**
 * The &, |, ^, ~, >> and << are only applied to integral types (hence, not doubles for example).
 * Hence for example, they can be applied to an enum as well.
 * 
 * Sometimes we use enums to define a set of values, which are the conclusion of union, intersection,
 * and asymmetric difference of the members. Take a look at this for example and note that ios_base
 * is a namespace:
 * enum ios_base::iostate { goodbit=0, eofbit=1, failbit=2, badbit=4};
 * 
 * These bit manipulation operatios however should not be handled at the UI level however. At that level,
 * we should use set or bitset.
 * 
 * As we know, we can compute the bit content of integral value using bitwise operations.
 * 
 * How not to confuse ~ and bit? Remember that != is used as a logical operator. Hence, ! is logical, hence ~ is bitwise.
 * Don't forget that with bool however, YOU MUST USE !. Why? Because bool is a logical value, not a bit value!!!
 */
constexpr unsigned short calculateMiddle16Bits(int val){
    static_assert(sizeof(int) == 4, "Int is not 32 bit");
    
    // If by accident I put && here, the result would be ... 1. Because we return true, and then true converts to one!
    return (val >> 8) & 0xFFFF;

}

#include <iostream>
int main(){
    std::cout << calculateMiddle16Bits(2048);
}