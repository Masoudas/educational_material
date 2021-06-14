/**
 *  -   int isxdigit( int ch );
 * 
 * Checks if the given character is a hexadecimal numeric character (0123456789abcdefABCDEF) or is classified as 
 * a hexadecimal character.
 * 
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
 
int main(void)
{
    for (int ndx=0; ndx <= UCHAR_MAX; ndx++)
        if (isxdigit(ndx)) printf("%c", ndx);
    printf("\n");
}
