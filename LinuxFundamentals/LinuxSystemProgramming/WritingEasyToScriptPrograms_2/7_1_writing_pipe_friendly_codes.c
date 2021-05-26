/**
 * We need to make sure that errors in the program are printed to stderr as well, which is what we intend to
 * do in the following program.
 * 
 * strspn is an interesting function. The signature is size_t strspn(const char *s, const char *accept). That
 * is, it compares from the beginning of the string to the chars we've supplied in accept. It then returns 
 * the length of the substring from the beginning that contains these chars (which could be zero or etc).
 *
 * Also, recall that strlen calculates the string length excluding the final '\0', which is what normall people
 * do.
 * 
 * Now, we can clearly understand what the program does. It takes a look at the char string read from stdin
 * and if it's just numbers and points, converts it float, and then kphes it. On the other hand, if that's
 * not the case, then it returns an error. 
 * 
 * Notice that in the program, just printing to stderr does not terminate (just like a shell script of course.)
 * Rather, what does terminate the program is the return script.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char mph[10] = { 0 };
    while(fgets(mph, sizeof(mph), stdin) != NULL)
    {
        /* Check if mph is numeric (and do conversion) */
        if( strspn(mph, "0123456789.-\n") == strlen(mph) )
        {
            printf("%.1f\n", (atof(mph)*1.60934) );
        }

        /* If mph is NOT numeric, print error and return */
        else {
            fprintf(stderr, "Found non-numeric value\n");
            return 1;
        }
    }

    return 0;
}