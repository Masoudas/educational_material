/**
 *  -   int islower( int ch ) (int isupper(int c))
 * 
 * Checks if the given character is classified as a lowercase character according to the current C locale. In the
 * default "C" locale, islower returns true only for the lowercase letters (abcdefghijklmnopqrstuvwxyz).
 * 
 * If islower returns true, it is guaranteed that iscntrl, isdigit, ispunct, and isspace return false for the 
 * same character in the same C locale.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    if (islower('a')){
        printf("This was a lower case char\n");
    }
}