/**
 * In this example, we read from a file using file descriptors, and as such, we immitate an implementation of
 * the cat command.
 * 
 * To make matters a bit simpler, we define a fixed-sized buffer of 4096 length, we read into it, and then we
 * print it on the screen.
 * 
 * The bit that's very interesting about this program is the fact that file_size actually determines how many
 * chars there are inside the file. So let's say we wanted to read the entire file, we could just iterate over
 * this file with this condition, with the termination conditions 'n_read_chars > file_len'
 * 
 * Note: Notice that du command actually does not reflect this, and it shows a range for file size. For example,
 * for a file with only one char, it shows 4! However, ls -l takes it home and shows how many chars there are!
 * stat is another good command here, because it also shows exactly how many bytes there are in the command.
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAXSIZE 4096

int main(int argc, char *argv[])
{
   int fd; /* for the file descriptor */
   int maxread; /* the maximum we want to read*/
   off_t filesize; /* for the file size */
   struct stat fileinfo; /* struct for fstat */
   char rbuf[MAXSIZE] = { 0 }; /* the read buffer*/
    
   if (argc != 2){
      fprintf(stderr, "Usage: %s [path]\n", argv[0]);
      return 1;
   }

	/* open the file in read-only mode and get the file size */
   if ( (fd = open(argv[1], O_RDONLY)) == -1 )
   {
      perror("Can't open file for reading");
      return 1;
   }

   fstat(fd, &fileinfo);
   filesize = fileinfo.st_size;
   /* determine the max size we want to read so we don't overflow the read buffer */
   if ( filesize >= MAXSIZE )
      maxread = MAXSIZE-1;	// For EOF I guess, we need to read one char less!
   else{
      maxread = filesize;
	  printf("Here\n");
   }
    
   /* read the content and print it */
   if ( (read(fd, rbuf, maxread)) == -1 )
   {
      perror("Can't read file");
      return 1;
   }
   
   /* added by yours truly, so that we have a new line at the end if one does not exist*/
   if (rbuf[maxread - 2] != '\n')
   {
	   rbuf[maxread - 1] = '\n';
   }

   printf("%s", rbuf);
   return 0;
}