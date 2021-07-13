/**
 * Reminder: A child process can't send variables to parent process. Hence, the following sets variables for this
 * process and its children, i.e, in this environment and its children. Note that when we execute a binary, the
 * shell creates a CHILD PROCESS for us. Therefore, those variables won't be available for the current process.
 * Hence, echo $FULLNAME returns nothing below! This of course the same as trying to export a variable inside a
 * shell script.
 * 
 * The function is 'int setenv(const char *name, const char *value, int overwrite)'. It's in the stdlib, and the
 * documentation states that:
 * 
 * The  setenv() function adds the variable name to the environment with the value value, if name does not already 
 * exist. If name does exist in the environment, then its value is changed to value if overwrite is nonzero; if 
 * overwrite is zero, then the value of name is not changed. (and setenv() returns a success status). This function 
 * makes copies of the strings pointed to by name and value (by contrast with putenv(3).)
 * 
 * 
 */

#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setenv("FULLNAME", "Jack-Benny", 1);
    printf("Your full name is %s\n", getenv("FULLNAME"));
    return 0;
}