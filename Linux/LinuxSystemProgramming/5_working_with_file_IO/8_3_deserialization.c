/**
 * Deserialization can be done using the fread function, as shown below. Notice that:
 * 
 * 	-	The argument given to fopen is rb
 * 	-	Again, notice the length and number of bytes per entity that we say should be read.
 */

#include <stdio.h>
int main(int argc, char* argv[])
{
   FILE *fp;
   float x[2];
   if ( (fp = fopen(argv[1], "rb")) == 0 )
   {
      fprintf(stderr, "Can't open file for reading\n");
      return 1;
   }

   fread(&x, sizeof(float), sizeof(x) / sizeof(float), fp);
   printf("The first number was: %f\n", x[0]);
   printf("The second number was: %f\n", x[1]);
   fclose(fp);

   return 0;
}