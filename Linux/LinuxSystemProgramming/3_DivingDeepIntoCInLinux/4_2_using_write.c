/**
 * There isn't actually much difference between using a function from the standard C library versus using a system 
 * call function. System calls in Linux are declared in unistd.h (standard unix header files), so we need to 
 * include this file when using system calls.
 * 
 * The integer fildes here referred to here is a file descriptor. To write to a particular file or a socket,
 * read the man pages. Note that file descriptors are used rather than streams, because they're more primitive
 * than streams. In fact, file streams are layered on top of file descriptors.
 * 
 * Of course, note that a higher level version of this function would be fputs.
 * 
 */

#include <unistd.h>
int main(void)
{
	write(2, "hello, world\n", 13);
	return 0;
}