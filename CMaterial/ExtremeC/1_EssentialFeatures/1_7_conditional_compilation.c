/**
 * The directives used are:

#ifdef
#ifndef
#elif
#else
#endif

 * Note that when we define a macro, we don't necessarily have to assign a value to it. The simple act of defining it
 * informs the preprocessor to use it.
 * 
 * Reminder: Macros can be defined with the -D flag. In CMake, we can use the add_compile_features for a target to
 * this end. Also recall that we could configure a header file there as well.
 * 
 * Of course, the most famous usage of #ifndef is for headers as guards. If the macro is not defined, it would be defined
 * and placed in the translation unit. Notice the use of endif at the end:
 
#ifndef HEADER	// If not defined, use the rest of this file.
#define HEADER


#endif

 * Finally, note that #pragma once is the directive we use, which is not the standard.
 */