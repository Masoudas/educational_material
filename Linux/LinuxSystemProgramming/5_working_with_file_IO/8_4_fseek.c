/**
 * Same as we can use lseek to move the cursor to a particular part of the file with file descriptors, we
 * can use fseek with file descriptors.
 * 
 * Here's how to use this program:
 
 $ ./stream-seek /etc/passwd 2000 2100

 * Notice the use of ftell. Because we read char by char, we use ftell to determine the current char position
 * of the cursor. If this position exceeds the char number, we exit. So essentially, we're not using a counter
 * to count the number of chars.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if ( argc < 3 || argc > 4 )
   {
      fprintf(stderr, "Usage: %s [path] [from pos]"
         " [to pos]\n", argv[0]);
      return 1;
   }
 
   FILE *fp; /* pointer to a file stream */
   /* open file with read mode */
   if ( (fp = fopen(argv[1], "r")) == NULL )
   {
      perror("Can't open file for reading");
      return 1;
   } 
    
   fseek(fp, atoi(argv[2]), SEEK_SET);
   int ch; /* for each character */
   /* loop over each line and write it to stdout */
   while( (ch = fgetc(fp)) != EOF )
   {
      if ( argv[3] != NULL)
      {
         if ( ftell(fp) >= atoi(argv[3]) )
         {
            break;
         }
      }
      putchar(ch);
   }

   printf("\n");
   fclose(fp); /* close the stream */
   return 0;
}