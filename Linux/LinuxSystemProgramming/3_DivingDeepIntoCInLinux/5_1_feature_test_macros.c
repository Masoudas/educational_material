/**
 * What are the test macros we've included on top of some of the files so far? They have to do with standards,
 * ensuring that the libraries or C compiler we use are not below a particular standard. An example is the 
 * _XOPEN_SOURCE 500 we used when defining getopt function. 
 * 
 * A feature test macro controls the definitions that are exposed by system header files. We can leverage this in 
 * two ways. Either we can use it to create portable applications by using a feature test macro that prevents us 
 * from using non-standard definitions or we can use it the other way around, allowing us to use non-standard 
 * definitions.
 * 
 * Consider the following program, where we use the strdup for duplicating an string. Now, if we use this function
 * using the c99 standard, we'd get an error, because it's not defined in there. In particular, if a function is
 * not declared in this standard, it will be declared for us. Now, if we execute the code, we get a segmentation
 * fault error, which is related to pointer access. Note that if we execute the program, it may succeed on some
 * distros, and not on others, which is odd! This will be covered later.
 * 
 * Now, if we go to c11 or c17, it will still fail, but succeeds with c2x.
 * 
 * Now, aside from the c standard tweak, let's set the _XOPEN_SOURCE to 700 (note that it's very important that
 * it's put before the inclusion lines, otherwise, the definition will be after the declaration, which will not
 * activate the functions.) This time around, we see that function is activated. Also, recall that we can add
 * this definition upon compilation using the -D option, or in cmake by using the add_compile_definitions func.
 * 
 * Now, if we read the man page for the strdup command, we see that it has the following doc on feature test macro
 * addition:
 
_XOPEN_SOURCE >= 500
               || // Since glibc 2.12: // _POSIX_C_SOURCE >= 200809L
               || // Glibc versions <= 2.19: // _BSD_SOURCE || _SVID_SOURCE
 
 * What it tells us in plain English is that we can either include _XOPEN_SOURCE greater than equal 500, or
 * _POSIX_C_SOURCE 200890L or greater or _BSD_SOURCE or _SVID_SOURCE to ensure that this function is included as
 * part of the posix standard.
 * 
 * Note: Indeed, if instead of c17, we use gnu17, this problem is solved by default, which is in fact the default
 * standard used.
 */

//#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <string.h>


int main(){
	char a[] = "My string";
	char *b;

	b = strdup(a);
	printf("%s\n", b);

	return 0;
}