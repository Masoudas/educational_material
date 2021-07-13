/**
 * Often, functions that run into problems in the Linux world return -1 for errors, and most these errors have something
 * to do with memory limits or access violation. Famous examples are creat, open and write. This is specified in the 
 * RETURN VALUE section of their man pages, and they also set errno to particular values.
 * 
 * As opposed to that, a function like pow that returns values returns special values HUGE_VAL, HUGE_VALF or HUGE_VALL
 * on most systems in case of an error, and they often correspond to infinity. 
 * 
 * Other sort of errors are overflow errors, which happen in case of overflow not only of ints, but strings as an example.
 * For example, a function like strcat, strdup or strcpy might overflow. The solution in these cases is to use numbered
 * version, which are by and large safer, such as strncpy, strncat, stdndup, etc.
 * 
 */

#include <stdio.h>
#include <math.h>
int main(void)
{
   int number = 9999;
   double answer;
   if ( (answer = pow(number, number)) == HUGE_VAL )
   {
      fprintf(stderr, "A huge value\n");
      return 1;
   }
   else
   {
      printf("%lf\n", answer);
   }
   return 0;
}