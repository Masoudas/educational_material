/*
* This is not Bjarne.
* 
* An include (or import in other languages) is a mechanism that causes the content of the included 
* to be copied in the file. 
* 
* The #include preprocessor directive causes the compiler to replace that line with the entire text 
* of the contents of the named source file (if included in quotes: "") or named header (if included 
* in angle brackets: <>).
* 
* Note that a header doesn't need to be a source file. It can be any file, but is typically a file
* with .h or .hpp or .hh extension. The standard library headers don't include the .h as well,
* while in C standard headers have identifiers in the form of filenames with a ".h" extension, as 
* in #include <stdio.h>.
* 
* THE ONLY DIFFERENECE between quotation and angle bracker include is that quotation does not search for
* standard headers in the C++.
* What is usually done is that the angle-brackets form searches for source files in a standard system 
* directory (or set of directories), and then searches for source files in local or project-specific 
* paths (specified on the command line, in an environment variable, or in a Makefile or other build file), 
* while the form with quotes does not search in a standard system directory, only searching in local or 
* project-specific paths.
* 
* Hence, we may use angle brackets to point to all headers. However, this is considered poor form.

//#include <stdio.h>  // Include the contents of the standard header 'stdio.h' (probably a file 'stdio.h').
//#include <vector>  // Include the contents of the standard header 'vector' (probably a file 'vector.h').
//#include "user_defined.h"  // Include the contents of the file 'user_defined.h'.

* (Me: The circular problem remains still an issue. This means two files trying to include one another).
*/