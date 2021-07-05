/**
 * To create a hard link using bash commands, we know that we can do so using "$ln file link_name". The method
 * "link" in the "unistd" header is apparently the method to use (why this header one wonders?!) The documentation
 * says "The link() function shall create a new link (directory entry) for the existing file, path1, ... and the 
 * link count of the file shall be incremented by one."
 * 
 * Recall that hard links to libraries are not allowed. Moreover, a link to a symbolic link is implementation
 * defined. Note that the calling process must have enough previliges to create such a link. See also linkat
 * function.
 * 
 * Question: Do we want to check whether the file already exists before creating a link? Not particularly, because
 * the errno header takes care of that for us.
 */

#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	if (argc < 2){
		return 1;
	}

	if (link(argv[1], argv[2]) != 0){
		perror("Can't make the symbolic link");
		return 1;
	}

	return 0;
}