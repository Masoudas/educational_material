/**
 * In this receipe, we shall print messages to stdout and std error.
 * 
 * Now, note that printf prints to stdout. However, fprintf can be directed to stream to either stdout or
 * stderror, because it takes an streaming source.
 * 
 * Finally, note that with dprintf, we can use file descriptors directly to print to a file. Now, to use file
 * descriptors, we need a certain macro called _POSIX_C_SOURCE included, which we did of course.
 * 
 * To prove to ourselves that these are valid, we can execute and direct error messages to /dev/null:
 * $ ./program 2> /dev/null
 * $ ./program 1> /dev/null
 * 
 * Note that if we were to include unistd.h, we could also use macro names for the three file descriptors.
 */

#include <stdlib.h>
#include <stdio.h>

#define _POSIX_C_SOURCE 200809L

int main(){
    printf("A regular message\n");

    fprintf(stdout, "Also a regular message\n");
    fprintf(stderr, "An error message\n");

    // Courtesy of above macro, we can use these.
    dprintf(1, "Another regular message\n");
    dprintf(2, "Another error message\n");

    return EXIT_SUCCESS;
}