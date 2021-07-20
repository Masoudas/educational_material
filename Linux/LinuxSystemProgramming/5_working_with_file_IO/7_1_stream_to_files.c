/**
 * Same as we stream to stdout or stderr, it's possible to stream to our custom made file descriptors. The only
 * thing we need to do is to pass the descriptor to a function like fprintf or dprintf.
 * 
 * Is this method superior to using the system write function? Well, fprintf is more powerful than a normal buffer
 * certainly. Streams are buffered, and that's the most important advantage they have over normal file descriptors.
 * 
 * To get a file stream rather than a simple file descriptor, we use the fopen function instead of open. Note
 * that there's also a fdopen to convert a file descriptor to a file stream. Note that w+ opens for read and 
 * write, but does not append to existing file. For appending, use a+.
 * 
 * We also in the end, close the file stream using fstream, which is safer than not closing it.
 * 
 * It's very interesting to note that writing does not happen so long as the buffer is not full with this program.
 * Hence, if I press CTRL+C (kill signal) rather than CTRL+D (EOF on the stream) to exit the program, the buffer
 * would not actually flush! Interesting fact. Notice that after we press CTRL+D, the line that's not read from
 * the input stream is still written.
 */

#include <stdio.h>

// Write the second argument to the path specified by the first file.
// We also ask for stdin to be written as well.
int main(int argc, char* argv[]){

	FILE *fp;	// Our file stream entity.
	if (!(fp = fopen(argv[1], "w+"))){	// Create a file and if null, execute this loop.
		perror("Can't create the file.");
		return 1;
	}

	fprintf(fp, "%s", argv[2]);

	// Also, get strings from std in as well:
	char line[100] = {'\0'};
	while(fgets(line, 100, stdin)){	// Never ending loop again!
		if (!fprintf(fp, "%s", line)){	// Returns number of bytes writren
			fclose(fp);
			return 1;	// Could not write.
		}
	}

	fprintf(fp, "After the EOF sent to terminal, this was written");
	fclose(fp);
	return 0;
}