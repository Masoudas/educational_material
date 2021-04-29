/**
 * The motivation behind this piece came when I was trying to parse command line in OpenCV, using 
 * CommandLineParser.
 * 
 * So, recall that normally the binary to a program is defined on the path, and we usually don't execute it from
 * the folder it's in. For example, for myBin that's in usr/bin, we may do"
 * 
 * masoud@host:~$ ./usr/bin/myBin file.txt
 * 
 * Now, note that the path from which the program was executed is ~, and the user has passed a file.txt, which
 * needs to be parsed as such. So the question is, how can we resolve the path to file.txt?
 * 
 * Apparently, there's no unform way to do so, and each of LINUX and WINDOWS have their own thing. So, we need
 * to define a precompiler processor, in which we have a #define, whose value is set based on a conditional,
 * depending on whether our OS is WINDOWS or not. The function that's called in Windows is called _getcwd
 * and in Linux it's called getcwd.
 * 
 * Finally, note that we need to specify a define called FILENAME_MAX which is in stdio.h, which determines
 * the maximum allowable size of a path.
 * 
 * Also note that over the Internet, people have suggested "If you agree that some (portable) dependency on a 
 * near-standard lib is okay: Use Boost's filesystem library and ask for the initial_path()."
 */

#include <stdio.h>  // To have access to FILENAME_MAX macro
#ifdef WINDOWS
    #include <direct.h>
    #define getPWD _getcwd
#else
    #include <unistd.h>
    #define getPWD getcwd
#endif

void get_pwd(){
    char buffer[FILENAME_MAX];

    if (getPWD(buffer, sizeof(buffer))){    // Returns nullptr if empty
        printf("Couldn't get the path");
    }

    printf("The path is %s", buffer);
}