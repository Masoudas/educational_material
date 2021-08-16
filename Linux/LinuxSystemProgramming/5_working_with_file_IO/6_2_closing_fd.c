/**
 * In the following example, we shall first open a file, and then close it, before exiting the program.
 * 
 * Me: Note that there's no talk of exceptions here, because C does not have exceptions! We rather have to check
 * system function return values, or errno for the source of our problems.
 * 
 * For the sake of humanity, we shall not create a new file with open!
 */
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	int fd;
	
	if ( (fd = open(argv[1], O_APPEND | O_WRONLY)) == -1 ){
		fprintf(stderr, "Can't open file %s: %s\n", argv[1], strerror(errno));
		return 1;
	}

	if ( write(fd, argv[2], strlen(argv[2])) != strlen(argv[2])){
		fprintf(stderr, "Can't write to file: %s\n", strerror(errno));
		return 1;
	}

	close(fd);
	return 0;
}