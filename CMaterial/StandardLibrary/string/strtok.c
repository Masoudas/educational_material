/**
 * Me: Tokenizes an string. That is, finds from a set of chars we've given as a token, and returns whatever is
 * between the tokens. For example /This/is/Good with token '/' returns "This" and "is" and "Good". It replaces
 * the token char with '\0' inside the string, so no new string is allocated, nor is it just returning an
 * innocent pointer. Repetitive calls must be done by passing NULL. Now, because this function is destructive,
 * we can't pass a string literal to it. We MUST pass a char array.
 * 
 * Me: See also strbrk.
 * 
 * Finds the next token in a null-terminated byte string pointed to by str. The separator characters are 
 * identified by null-terminated byte string pointed to by delim. 
 * 
 * This function is designed to be called multiple times to obtain successive tokens from the same string.
 * 
 *  -   If str is not a null pointer, the call is treated as the first call to strtok for this particular string. The 
 *      function searches for the first character which is not contained in delim.
 *      -   If no such character was found, there are no tokens in str at all, and the function returns a null 
 *          pointer.
 *      -   If such character was found, it is the beginning of the token. The function then searches from that 
 *          point on for the first character that is contained in delim.
 *          -   If no such character was found, str has only one token, and the future calls to strtok will 
 *              return a null pointer.
 *          -   If such character was found, it is replaced by the null character '\0' and the pointer to the 
 *              following character is stored in a static location for subsequent invocations.
 *      -   The function then returns the pointer to the beginning of the token
 *  -   If str is a null pointer, the call is treated as a subsequent call to strtok: the function continues from 
 *      where it left in previous invocation. The behavior is the same as if the previously stored pointer is 
 *      passed as str.
 */

#include <string.h>
#include <stdio.h>

void tokenization_example(){
   char input[100] = {"/A bird came down the walk "};
   const char* delim = "/";
   char *token = strtok(input, delim);

   while (token) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
   }
}

int main(){
    tokenization_example();
}