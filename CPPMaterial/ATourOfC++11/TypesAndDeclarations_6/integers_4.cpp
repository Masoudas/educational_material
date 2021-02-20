/**
 * Integers come in three flavours, int, unsigned int and signed int.
 * They also come in four forms, short int, int, long int, long long int.
 * 
 * short is guaranteed at least 16 bits, long at least 32 bits.
 * 
 * Default value is a suitable representation of zero for all types (when used with bracket notion for example.)
 *  
 * Note that short is a synonym for short int.
 * unsigned is sysnonym for unsigned int, and singed for signed int.
 * 
 * Using an unsigned instead of an int to  gain  one  more  bit  to  represent  positive
 * integers  is  almost  never a good  idea. Attempts  to  ensure  that  some  values  are  
 * positive  by declaring  variables unsigned will typically be defeated by the implicit conversion rules.
 * 
 * Unlike plainchars, plainints are always signed.  The signed int 
 * types are simply more explicit synonyms for their plain int counterparts, rather than different types.
 * 
 * the <cstdint> provide us with some type definition.
 * int64_t is a signed 64 bit. uint_fast16_t is an unsigned int with exactly 8 bits, supposedly the fastest
 * of such type, and so forth.
 * 
 * Note that size_t is an implementation defined unsigned int, and is usually used for indicating the 
 * size of an object.
 * 
 */
#include <iostream>
using namespace std;
void integer_initialization(){
    char x{};   // Initialized to zero
    int y{};    // Initialized to zero

    char x1; // Initialized to what is in the memory (stack).
    

}