/**
 * In this example, we try and return from a function. Note that stdlib contains the macros EXIT_SUCCESS and
 * EXIT_FAILURE, which I use in this code. 
 * 
 * Notice that in this particular example, depending on our compilation flag EXIT defined or not, we exit either
 * with exit function or with return value from func1 and 2. Note that of course if the code is compiled with
 * the EXIT flag (gcc -DEXIT ...) the code exits from nested functions with the given return value. 
 * 
 * We however don't exit from intermediary functions because we're not crazy.
 */

#include <stdlib.h>
#include <stdio.h>

int func1(void);
int func2(void);

int main(int argc, char *argv[])
{
   printf("Inside main\n");
   printf("Calling function one\n");
   if (func1())
   {
      printf("Everything ok from function one\n");
      printf("Return with 0 from main - all ok\n");
      return EXIT_SUCCESS;
   }
   else
   {
      printf("Caught an error from function one\n");
      printf("Return with 1 from main - error\n");
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS; /* We shouldn't reach this, but 
                just in case */
}
int func1(void)
{
   printf("Inside function one\n");
   printf("Calling function two\n");
   if (func2())
   {
      printf("Everything ok from function two\n");
      #ifdef EXIT
      exit(1);
      #else
      return 1;
      #endif
   }
   else
   {
      printf("Caught an error from function two\n");
      #ifdef EXIT
      exit(0);
      #else
      return 0;
      #endif
   }
}
int func2(void)
{
   printf("Inside function two\n");
   printf("Returning with 0 (error) from "
      "function two\n");
    #ifdef EXIT
    exit(0);
    #else
    return 0;
    #endif
}