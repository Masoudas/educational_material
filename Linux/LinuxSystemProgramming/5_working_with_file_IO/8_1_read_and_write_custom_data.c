/**
 * The original title of this section is "Reading and writing binary data with streams." The goal of this section
 * to write arbitray data (and not just strings) to a file.
 * 
 * Naturlich, we once again use streams and in particular fprintf. This is because it will allow us to format our
 * streams, for example using %f.
 * 
 * First, let's do it in a normal format, so that we see what's going on. For this end, we use fprintf, which is
 * fine.
 * 
 * In the next file, we shall demonstrate how to write this information as a binary data stream.
 */

#include <stdio.h>
int main(void)
{
   FILE *fp;
   float x[2];
   
   if ( !(fp = fopen("my-binary-file", "w+")))
   {
      fprintf(stderr, "Can't open file for writing\n");
      return 1;
   }
   printf("Type two floating point numbers, separated by a space: ");
   scanf("%f %f", &x[0], &x[1]);

   // My version using fprintf	
   fprintf(fp, "%.3f %.3f\n", x[0], x[1]);

   fclose(fp);
   return 0;
}