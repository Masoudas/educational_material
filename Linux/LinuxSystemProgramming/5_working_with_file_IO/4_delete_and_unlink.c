/**
 * The function to remove a file is actually unlink, which is used to remove any links to a particular node.
 * The function is in the unistd header. If a symbolic link is passed to it, it does not follow it, but rather
 * removes the link file. Note that we can't use unlink for directories. For dirs we shall use rmdir. In the 
 * end, the file is deleted from memory once there are no hard links to it.
 * 
 * Note: After searching the headers, I found that actually remove is a better method for our purposes, inside
 * the stdio library.
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [path]\n", argv[0]);
        return 1;
    }

    if ( unlink(argv[1]) == -1 )
    {
        perror("Can't remove file");
        return errno;
    }
    return 0;
}
