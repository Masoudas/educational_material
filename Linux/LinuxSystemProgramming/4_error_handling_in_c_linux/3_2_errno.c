/**
 * Consider the following example, where we try to create a file with 'creat' function. Apart from the -1 return value,
 * the errno is set by this function. We see in the ERRORS section that errno may be set to the following values:
 * 
 * 	-	EACCES:	The requested access to file is not allowed.
 * 	-	EEXIST:	Already exists
 * 	-	EFAULT: Points to outside of accessible namespace.
 * 	-	ENOENT: No entry (meaning the parent folder does not exist.)
 * 	...
 * 
 * The point is that errno is set once the file cannot be created, that is, once the function returns -1. 
 * 
 * To gain access to errno variable, we need to include the errno header.
 * 
 * Note: Some say this program is equivalent to touch.
 */

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	if (argc < 2){
		return;
	}
	mode_t file_mode = 00644;	// Check out 2_1

	if (creat(argv[1], file_mode) == -1){	// Some kind of error has occurred.
		if (errno == EACCES){
			fprintf(stderr, "Can't create file due lack of access\n");
		}
		return 1;
	}

	fprintf(stdout, "Successfully created the file\n");
	return 0;
}