/**
 *  -   int isalnum( int ch );
 *
 * Me: Alpha stands for alphabetic you morron!
 * 
 * Checks if the given character is an alphanumeric character as classified by the current C locale. In the default 
 * locale, the following characters are alphanumeric:
 * 
 *  -   digits (0123456789)
 *  -   uppercase letters (ABCDEFGHIJKLMNOPQRSTUVWXYZ)
 *  -   lowercase letters (abcdefghijklmnopqrstuvwxyz)
 * 
 * The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
 */

#include <stdio.h>
#include <ctype.h>
#include <locale.h>
 
int main(void)
{
    unsigned char c = '\xdf'; // German letter ß in ISO-8859-1
 
    printf("isalnum('\\xdf') in default C locale returned %d\n", !!isalnum(c));
 
    if(setlocale(LC_CTYPE, "de_DE.iso88591"))
        printf("isalnum('\\xdf') in ISO-8859-1 locale returned %d\n", !!isalnum(c));
}


