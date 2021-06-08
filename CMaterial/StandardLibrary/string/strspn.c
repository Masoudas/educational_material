/**
 * Me: AKA string span.
 * 
 * -    size_t strspn( const char *dest, const char *src )
 * 
 * Returns the length of the maximum initial segment (span) of the null-terminated byte string pointed to by dest, 
 * that consists of only the characters found in the null-terminated byte string pointed to by src.
 * 
 * The behavior is undefined if either dest or src is not a pointer to a null-terminated byte string.
 * 
 * dest	-	pointer to the null-terminated byte string to be analyzed
 * src	-	pointer to the null-terminated byte string that contains the characters to search for
 */

#include <string.h>
#include <stdio.h>
 
void computingSpan(void)
{
    const char *string = "abcde312$#@";
    const char *low_alpha = "qwertyuiopasdfghjklzxcvbnm";
 
    size_t spnsz = strspn(string, low_alpha);
    printf("After skipping initial lowercase letters from '%s'\n"
           "The remainder is '%s'\n", string, string+spnsz);
}