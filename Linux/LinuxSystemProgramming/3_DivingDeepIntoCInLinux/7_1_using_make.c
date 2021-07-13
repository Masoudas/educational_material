/**
 * As it turns out, we can use make directly with our .c files to compile them, without having to specify any
 * receipes.
 * 
 * Also of interest, if the program has not changed, Make will not recompile the program, which is impressive!
 * For example below, unless I change the definition macro, nothing will be recompiled.
 * 
 * Note that we don't need to specify the extension of the file:
 * $ make prog
 * 
 * Also note that make by default uses cc as link to compiler, which is why we may pass CC variable to it to
 * change the compiler.
 * 
 * CC=clang make prog
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.141591

int main(void)
{
   char radius[20] = { 0 };
   while(fgets(radius, sizeof(radius), stdin) 
      != NULL)
   {
      /* Check if radius is numeric 
       * (and do conversion) */
      if( strspn(radius,"0123456789.\n") == 
         strlen(radius) )
      {
         printf("%.5f\n", PI*(atof(radius)*2) );
      }
      /* If radius is NOT numeric, print error 
       * and return */
      else
      {
         fprintf(stderr, "Found non-numeric "
            "value\n");
         return 1;
      }
   }
   return 0;
}
