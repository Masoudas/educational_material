/**
 * To write to a text file, we need to first OPEN it, and then write to it using the WRITE function. Now, a
 * 'man 3 open' gives the following signature:
 * 
 * int open(const char *path, int oflag, ...);
 * 
 * Note that open creates a file descriptor, and that is what's returned by the file descriptor. The oflag
 * parameter determines the openning mode, which in our case would be O_WRONLY | O_APPEND | O_CREAT.
 * 
 * Now, because we've supplied the O_CREAT flag above, we need to supply a mode_t parameter for the case the 
 * file does not exist and needs to be created. This flag would be 00644.
 * 
 * Note that file descriptors are closed automatically in essense, but we can close them explicitly using the
 * close method.
 * 
 * Notice that we can even pipe from another file to our program to write the content of that file into our
 * file as follows:
 * 
 * head -n 5 other_file | xargs -0 ./our_program File
 * 
 * Question: Why do we need the -0? Because we want whitespace and newlines to be passed as is to our program.
 * As such, when our string buffer is formed, it will have our white space and new lines embedded it. So long as
 * xargs does not reach '\0', it will keep everything. That way, new lines and spaces would be copied into the
 * file we write to. Otherwise, white spaces and new lines would be like passing new arguments to our_program!
 * 
 * Note: Something interesting about passing a literal string is that '\n' is not interpreted as a new line!
 */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
	if (argc != 3)
    {
       fprintf(stderr, "Usage: %s [path] [string]\n", argv[0]);
       return 1;
    }

	int fd = 0;
	if ((fd = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, 00644)) == -1){
		perror("Can't open file");
	}

	size_t write_size = 0;
	if ( (write_size = write(fd, argv[2], strlen(argv[2]))) != strlen(argv[2])){
		fprintf(stderr, "Could not write to the file\n");
	}
}