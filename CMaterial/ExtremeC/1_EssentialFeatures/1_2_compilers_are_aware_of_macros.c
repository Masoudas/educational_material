/**
 * That being said, compilers are generally aware of macros, which would help them produce meaningful error messages.
 * For example, consider the following, where backslash like always continues the line of code on the next line:

#include <stdio.h>
#define CODE \	
	printf("%d\n", i);
int main(int argc, char** argv) {
 	CODE
 	return 0;
}

 * Using clang on macos, we get the following error:

code.c:7:3: error: use of undeclared identifier 'i'
CODE
^
code.c:4:16: note: expanded from macro 'CODE'
printf("%d\n", i);
               ^
1 error generated.

 * Reminder: In most modern compilers, we can see the result of preprocessor using the -E option (especially clang and
 * gcc.)
 * 
 * A translation unit (or a compilation unit) is the preprocessed C code that is ready to be passed to the compiler.
 */