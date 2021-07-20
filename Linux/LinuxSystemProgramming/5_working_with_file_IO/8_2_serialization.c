/**
 * In this example, we write the same stream, but as binary. This implies that we convert a floating point to the
 * actual bits that form it.
 * 
 * Now, why would we want to do this? Well, for starters, this would allow us to stream any object we require 
 * directly into memory, not having to deal with individual elements. As such, serialization of any data form would
 * be possible.
 * 
 * Notice that we did two important things here:
 * 	-	We opened the file in b format.
 * 	-	We used the fwrite function, which takes a pointer to void as argument. Also notice that the second arg of
 * 		this method is the element size, and third is the total number of elements.
 * 
 * As such, when we read this data back from memory, we copy the exact bits into memory, and then we'd have the
 * same info as before.
 * 
 * Now, notice that using hexdump with the -C option, we can actually check out the content of the bits on the
 * command line:
 * $ hexdump -C file

00000000  cd cc 8c 3f cd cc 0c 40                           |...?...@|
00000008
 
 * We see that each we have exactly eight hex values here, which does make sense, because every float on my machine
 * is actually 32 bits.
 */

#include <stdio.h>
int main(int argc, char* argv[]){
   FILE *fp;
   float x[2];
   if ( (fp = fopen(argv[1], "ab+")) == 0 ) {
      fprintf(stderr, "Can't open file for writing\n");
      return 1;
   }

   printf("Type two floating point numbers, separated by a space: ");
   scanf("%f %f", &x[0], &x[1]);

   fwrite(&x, sizeof(float), sizeof(x) / sizeof(float), fp);
   fclose(fp);
   return 0;
}