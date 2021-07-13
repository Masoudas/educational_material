/**
 * It's a good idea to thus to return the error value, even though we should be cautious that this does not correspond to
 * the standard shell error values (like 127 for command does not exist, 2 for Misuse of shell builtins, etc.)
 * 
 * There is a small program called errno that can print all macros and their integers. This tool isn't installed by 
 * default, though. The name of the package is moreutils.
 *
 * Once installed, you can print a list of all the macros by running the errno -l command, where the l option stands for 
 * list.
 * 
 * To install the package in Debian and Ubuntu, type apt install moreutils as root.
 * 
 */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>

int main(int argc, char *argv[])
{
   char filename[PATH_MAX] = { 0 };
   if (argc != 2)
   {
      fprintf(stderr, "You must supply a filename as an argument\n");
      return 1;
   }
   
   strncpy(filename, argv[1], sizeof(filename)-1);
   if ( creat(filename, 00644) == -1 )
   {
      perror("Can't create file");
      return errno;
   }

   return 0;
}