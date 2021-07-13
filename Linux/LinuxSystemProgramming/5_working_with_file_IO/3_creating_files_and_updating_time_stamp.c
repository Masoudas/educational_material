/**
 * In the following example, we shall try and immitate the behavior of the touch command. That is:
 * 	-	If the given name does not exist, we shall create one
 * 	-	If the file does exist, we shall update its modification time. 
 * 
 * To that end, we shall use two functions:
 * 	-	creat:	In the fcntl header 
 * 	-	utime:	A function in the utime header used for accessing and changing modification and access time. 
 * 
 * So, the strategy of the program is to first try and check if we can change the modification time. If we can't
 * due the fact that errno variable equals ENOENT (no entry, or file does not exist,) then, we shall try and
 * create the file. Otherwise, we exit the program. Notice that if we didn't pass a utimbuf object in the second
 * argument, both access and modification time would be updated.
 * 
 * Note: As we can see time and again, we normally don't check for existence of file before manipulating it.
 * 
 * As a reminder, note that for two hard links to the same innode, using this program causes the access time of
 * both files to get updated.
 */

#include <stdio.h>
#include <fcntl.h>
#include <utime.h>
#include <errno.h>

int main(int argc, char* argv[]){
	if (argc < 2){
		return 1;
	}

	// If we can't update the time, possibly the file does not exist
	if (utime(argv[1], NULL) == -1){
		/* If the file doesn't exist, create it */
      if (errno == ENOENT)
      {
         if ( creat(argv[1], 00644) == -1 )
         {
            perror("Can't create file");
            return errno;
         }
      }
	  
      /* If we can't update the timestamp, something is wrong */
      else
      {
         perror("Can't update timestamp");
         return errno;
      }
   }
   return 0;
}
