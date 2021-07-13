/**
 * An alternative to stderror is perror, which directly prints the error messate to stderr. What it does is that it reads
 * the value currently held in errorno, and then prints the message corresponding to strerror. The const char* argument
 * we supply here simply is an extra error message.
 * 
 * For example, if I run the following command:
 
 $ ./prog /aa
 Can't create file: Permission denied

 * Tip: It's best to include the name of the function that caused the error in perror, to make debugging easier. Also,
 * read the man page perror
 */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>
int main(int argc, char *argv[])
{
   char filename[PATH_MAX] = { 0 };
 
   if (argc != 2)
   {
      fprintf(stderr, "You must supply a filename as an argument\n");
      return 1;
   }

   strncpy(filename, argv[1], sizeof(filename)-1);
   if ( creat(filename, 00644) == -1 )
   {
      perror("Can't create file");
      return 1;
   }

   return 0;
}