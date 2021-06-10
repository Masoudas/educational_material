/**
 * Note: Control chars are \n, \t, \f, \r, ^Z (EOF), etc, which are actually codes 0x00-0x1F and 0x7F.
 * 
 *  -   int iscntrl( int ch );
 * Checks if the given character is a control character, i.e. codes 0x00-0x1F and 0x7F.
 * 
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    if (iscntrl('\n') && iscntrl('\t') && iscntrl('^Z'))
        printf("%s", "All these are control chars");
}

