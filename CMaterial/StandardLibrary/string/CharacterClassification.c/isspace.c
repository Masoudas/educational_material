/**
 *  -   int isspace( int ch );
 * 
 * Checks if the given character is a whitespace character, i.e. either space (0x20), form feed (0x0c), line feed 
 * (0x0a), carriage return (0x0d), horizontal tab (0x09) or vertical tab (0x0b).
 * 
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
 
int main(void)
{
    for (int ndx=0; ndx <= UCHAR_MAX; ndx++)
        if (isspace(ndx)) printf("0x%02x\n", ndx);
}
