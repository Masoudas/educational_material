/**
 * As it turns out, if we don't set in any standards, the compiler will define ones of its own, (me: and 
 * particularly, if we include various versions of the standard I guess.)
 * 
 * In the following example, we investigate some of those default macros. In particular, pay attention to 
 * __STDC_VERSION__ macro, which determines which standard version was used. Notice that without any standard
 * being passed, the printed version is 201710, which is kind of what's expected, given that C2x is not approved
 * yet at 2021. Note that the default standard for gcc is in fact gnu2017.
 * 
 */

#include <stdio.h>

int main(){
	#ifdef __STDC_VERSION__
		printf("The standard version is %i \n", __STDC_VERSION__);
	#endif
	#ifdef _XOPEN_SOURCE
		printf("The _XOPEN_SOURCE_ version is: %i\n", _XOPEN_SOURCE);
	#endif
	#ifdef _POSIX_C_SOURCE
		printf("The _POSIX_C_SOURCE is: %i\n", _POSIX_C_SOURCE);
	#endif
	#ifdef _GNU_SOURCE
      printf("GNU_SOURCE: %d\n", _GNU_SOURCE);
    #endif
    #ifdef _BSD_SOURCE
      printf("BSD_SOURCE: %d\n", _BSD_SOURCE);
    #endif
    #ifdef _DEFAULT_SOURCE
      printf("DEFAULT_SOURCE: %d\n", _DEFAULT_SOURCE);
    #endif
   return 0;
}