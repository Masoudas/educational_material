/**
 * As we know, as opposed to the owner, a user can set the permission to the files it owns without having to use
 * sudo. In the following program, we shall do such an operation. The user is asked to provide a file name and
 * an octal (three digits) as arguments to our program, and we shall use them to set the permission of the requested
 * file.
 * 
 * The function to convert string to octal is strtol. Moreover the function that sets the permission has to be
 * a system function, and is thus in the sys headers. The function is pretty much called chmod in this header:
 * 
 * int chmod(const char *path, mode_t mode):
 * 		The  chmod()  function  shall change S_ISUID, S_ISGID, S_ISVTX, and the file permission bits of the file 
 * 	named by the pathname pointed to by the path argument to the corresponding bits in the mode argument. The 
 * 	application shall ensure that the effective user ID of the process matches the owner of the file or the 
 * 	process has appropriate privileges in order to do this.
 */

#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	if (argc < 2){
		return 1;
	}

	if ( strspn(argv[1], "01234567") != strlen(argv[1]) || (
		strlen(argv[1]) != 3 && strlen(argv[1]) != 4)){
			fprintf(stdout, "The given permission is not correct!");
	}

	__mode_t mode = strtol(argv[1], NULL, 8);
   if (chmod(argv[2], mode) == -1)
   {
      perror("Can't change permissions");
	  return 1;
   }

   return 0;
	
}