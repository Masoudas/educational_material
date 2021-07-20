/**
 * Same as writing using streams, we can read using streams as well. The mechanism is pretty much like the previous
 * example, and an example is given below.
 */

#include <stdio.h>
int main(int argc, char *argv[])
{
   char linebuf[1024] = { 0 }; /* line buffer */
   if ( argc != 2 )
   {
      fprintf(stderr, "Usage: %s [path]\n", argv[0]);
      return 1;
   }

   /* open file with read mode */
   FILE *fp; /* pointer to a file stream */
   if ( (fp = fopen(argv[1], "r")) == NULL )
   {
      perror("Can't open file for reading");
      return 1;
   } 
    
   /* loop over each line and write it to stdout. Notice the comparison to null for termination. */
   while(fgets(linebuf, sizeof(linebuf), fp) != NULL)
   {
      printf("%s", linebuf);
   }
   fclose(fp); /* close the stream */
   return 0;
}