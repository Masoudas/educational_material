/**
 * Here, we shall load from the math function lazily, and then use the abs method. Based on what we discussed
 * before, the process of loading the library is pretty much striaghforward. Note, however, that compiling this
 * program must be done as follows to link the dl library as follows:
 
 $ gcc -Wall -Werror -Wpedantic -ldl 7_2_example.c -o program

 * Technical point from me: Note that with Wpedantic, the compiler will complain about converting object pointer
 * to function pointer, if we implicitly cast the output of dlsym. This is technically the case, and should be,
 * because apparently pointer to functions don't have necessarily the same size as pointer to data (the former
 * could be 32 bit, while the latter can be 64.) In any case, removing Wpedantic solves this problem. Another
 * solution is the define the function pointer as a type, and then use the following notation to convert the void
 * pointer to a function pointer:
 
 f_ptr p = f_ptr(void_ptr);	// This doesn't work.
 
 * Another solution is:

void* voidptr = ...
int (*fptr)(int);
*(void**)(&fptr) = voidptr;

 * In any case, I found turning off the warnings the most useful solution. 
 */

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

typedef double (*cos_t)(double);

int main(){
	void* libmath = dlopen("/usr/lib/x86_64-linux-gnu/libm.so.6" , RTLD_LAZY);

	if (!libmath){
		fprintf(stderr, "Could not load the library: %s\n", dlerror());
		return 1;
	}
 
	cos_t fptr = (cos_t)dlsym(libmath, "cos");
	if (!fptr){
		fprintf(stderr, "Could not open the symbol: %s", dlerror());
	}

	fprintf(stdout, "cos of 0 is %f.\n", fptr(0));

	if (dlclose(libmath)){
		fprintf(stderr, "Could not properly close the library");
	}
	return 0;
}