/**
 *  -   int isdigit( int ch );
 *  Checks if the given character is a numeric character (0123456789).
 * 
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
 
int main(void)
{
    for (int ndx = 0; ndx <= UCHAR_MAX; ndx++)
        if (isdigit(ndx)) printf("%c", ndx);
        
    printf("\n");
}