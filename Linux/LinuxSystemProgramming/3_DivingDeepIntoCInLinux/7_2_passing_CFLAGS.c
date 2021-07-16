/**
 * A simple Make file may not necessarily have a build receipe, but we can just define the CFLAGS and CC as a full Make
 * file. Consider:

 /Makefile
CC=clang
CFLAGS=-Wall -Wpedantic -Wextra -std=c99
LFLAGS=-Wl

 * Notice two things:
 *	1)	Note that we must make a Makefile and NOT a MakeFile
 *	2)	Notice that the options are passed without a string surrounding them, which is kind of odd.
 *
 * Now, just like before, using this MakeFile with an arbitrary file will build that file:

$ make prog

 * One last thing is that as we may recall, we can pass these variables before the command. However, if these flags are
 * defined as shown before, the flags defined inside the Makefile are used, and ours are ignored (which makes all the
 * sense in the world CMake!)
 */
