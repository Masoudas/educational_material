/**
 * The code that we write in this example will be compiled as a dll. To compile a code as a dll, first we need 
 * to create PIC codes, and then we can create the .so archive using the '-shared' option. Note that at the
 * compilation stage we only need the object file, and as such we supply the -c option.
 * 
 * $ gcc -Wall -Wextra -Wpedantic -fPIC -c program.c
 * $ gcc -shared -Wl,-soname,libprime.so -o libprime.so program.o	
 * 
 * Note that after -o we first give the library name, then object files.
 * What are the linkeage options then (See gcc Compiler?)
 * 	- Wl: 	Pass linker options.
 * 	- sonmae:	Set shared library soname.
 * 
 * Notice that the soname we give to this library is the same as the name of the library (libprime.so)
 */
