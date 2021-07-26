/**
 * When we open a file, we always essentially start from the top of the file to read. So, can we move further 
 * forward inside the file when we read it?
 * 
 * The answer is that lseek seeks a certain line of the text to start reading from it. The lseek() function 
 * moves the read head (sometimes called a cursor) inside the file descriptor to the position we specify. 
 * The cursor then remains at that position until we start read().
 * 
 * So for example with the following code, we could say"
 
 ./prog /etc/passwrd 10 100

 * The third argument to lseek(), SEEK_SET, is where the cursor should be located in relation to the value we 
 * give as the second argument. In this case, with SEEK_SET, it means that the position should be set to 
 * whatever we specify as the second argument. If we wanted to move the position relative to our current 
 * position, we would have used SEEK_CUR instead (like if we've already read a couple of lines and the cursor
 * is in a different positions). And if we wanted to move the cursor relative to the end of the file, we 
 * would have used SEEK_END.
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#define MAXSIZE 4096
int main(int argc, char *argv[])
{
   int fd; /* for the file descriptor */
   int maxread; /* the maximum we want to read*/
   off_t filesize; /* for the file size */
   struct stat fileinfo; /* struct for fstat */
   char rbuf[MAXSIZE] = { 0 }; /* the read buffer */

   if (argc < 3 || argc > 4)
   {
      fprintf(stderr, "Usage: %s [path] [from pos] "
         "[bytes to read]\n", argv[0]);
      return 1;
   }

   /* open the file in read-only mode and get
      the file size */
   if ( (fd = open(argv[1], O_RDONLY)) == -1 )
   {
      perror("Can't open file for reading");
      return 1;
   }

   fstat(fd, &fileinfo);
   filesize = fileinfo.st_size;

   /* determine the max size we want to read so we don't overflow the read buffer */
   if ( filesize >= MAXSIZE )
   {
      maxread = MAXSIZE-1;
   }
   else if ( argv[3] != NULL )
   {
      if ( atoi(argv[3]) >= MAXSIZE )
      {
         fprintf(stderr, "Too big size specified\n");
         return 1;
      }
      maxread = atoi(argv[3]);
   }
   else
   {
      maxread = filesize;
   }

   /* move the read position */
   lseek(fd, atoi(argv[2]), SEEK_SET);
   /* read the content and print it */
   if ( (read(fd, rbuf, maxread)) == -1 )
   {
      perror("Can't read file");
      return 1;
   }
   printf("%s\n", rbuf);
   return 0;
}