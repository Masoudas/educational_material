/**
 * Consider the following program. We can change the standard to C89 and compile:
 * gcc -std=c89 no-return.c -o no-return
 * 
 * Now if we echo $?, we get a 13 rather than 0.
 * 
 * However, if we try:
 * $> gcc -Wall -Wextra -pedantic -std=c89 no-return.c -o no-return
 * 
 * it warns us, but the compile the program. It's interesting that if we recompile the program with C99, we
 * don't get any errors and we return a 0!
 * 
 * As another example, a program like for (int i = 10; i>0; i--) is only allowed from c99. Hence, in older versions
 * of c, we get a warning saying upgrade to a higher standard and the program is not compiled.
 * 
 * Note that there are more C standards and dialects than just C89 and C99. Just to mention a few more, there are 
 * C11, GNU99 (GNU's dialect of C99), GNU11 (GNU's dialect of C11), and some others, but the most commonly used 
 * today are C89, C99, and C11. C18 is starting to appear as default for some compilers and distributions.
 */

#include <stdio.h>
int main(void)
{
    printf("Hello, world\n");
}