/** 
 * In this program, we shall learn how to read from stdin.
 * 
 * The function to read from an stream is called fgets. This function requires a char array, together with 
 * the stream source, which in our case is stdin.
 * 
 * So note that when we read using stdin, like always, so long as the stream has not been terminated by a 
 * carriage return, stdin continues. Once we're pressing enter, depending on how many chars we've supplied 
 * as the buffer, only that number of chars are read. However, whatever remains in the buffer is read the
 * next time we use this function!!! For example:
 
char c[20] = {0};    // Initialize an array of string.
fgets(c, sizeof(c), stdin);

// ... Do some operations
fgets(c, sizeof(c), stdin);

 * This means no matter how many chars we enter, only 20 of them are read. However, as soon as we read from
 * stdin again, first those chars that can not be put in the buffer are read again from the buffer!!! So, be
 * careful. Actually, the return pointer points to the fgets buffer for this reason. If we check the code 
 * below, we see that fgets is put in a while loop. This is because, so long as the buffer is not empty,
 * it returns a null, and we have to read from it. As opposed to just putting an if statement, which does not
 * get all the string the user puts (which maybe greater than 20 chars.) Of course, this mechanism is also
 * useful for getting several strings from input as well. Note also that like C++, pressing an enter after
 * an empty string does not return.
 * 
 * Programming side note: Note that if we said char c[20]; and forget the {}, the array would not have been
 * initialized. The array would have just been allocated on the memory in this case. That's why we need the
 * {}.
 * 
 * To make the program more interesting below, we also convert each letter to upper case. Here, the book uses
 * the famous addition to int value to make the letters uppercase, although we could actually use the toupper
 * function in the ctype header.
 * 
 * Finally, notice the use of the memset function to set the memory values to the value we seek. Kind of like
 * fill if you will.
 * 
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char c[20] = { 0 };
    char newcase[20] = { 0 };
    int i;

    while(fgets(c, sizeof(c), stdin) != NULL)  // Checking for non-empty string
    {
        for(i=0; i <= sizeof(c); i++)
        {
            /* Upper case to lower case */
            if ( (c[i] >= 65) && (c[i] <= 90) ) // We should and here!
            {
                newcase[i] = c[i] + 32;
            }
            /* Lower case to upper case */
            else if ( (c[i] >= 97 && c[i] <= 122) )
            {
                newcase[i] = c[i] - 32;
            }
            /* We may skip this portion if we just want to upper or lower case chars*/
            else {
                newcase[i] = c[i];
            }
        }
        
        printf("%.*s\n", sizeof(c), newcase);   // .* specifies minimum bit-field. Result is padded if not
                                                // enough chars.
    //    fprintf(stdout, c);
    
        /* zero out the arrays so there are no
           left-overs in the next run */
        memset(c, 0, sizeof(c));
        memset(newcase, 0, sizeof(newcase));
    }
    return 0;
}