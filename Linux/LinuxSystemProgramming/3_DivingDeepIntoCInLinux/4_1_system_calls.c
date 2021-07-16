/**
 * From a top down point of view, we use binaries or shellscripts, which use c function libraries such as printf,
 * which in turn use low-level system calls such as write or creater, and from here on, we move away from the user
 * land to the kernel land, where system call table would be used.
 * 
 * This is depicted in Figure 1.
 * 
 * By system calls we imply calling the functions provided by the kernel as C functions (with headers) and not
 * function tables. Many of the standard C library functions, such as putc(), use one or more system call functions 
 * behind the curtains. The putc() function is an excellent example; this uses write() to print a character on the 
 * screen (which is a system call). There are also standard C library functions that don't use any system calls at 
 * all, such as atoi(), which resides entirely in user space. There is no need to involve the kernel to convert a 
 * string into a number.
 * 
 * Generally speaking, if there is a standard C library function available, we should use that instead of a system 
 * call. System calls are often harder to work with and more primitive. Think of system calls as low-level 
 * operations, and standard C functions as high-level operations.
 * 
 * So operations however can be better performed using system calls. For example, some file opertions or fork() a
 * process.
 * 
 * Tip:
 * 	Most system calls will return -1 if an error occurs. It's generally a good idea to check for this value to 
 *  detect errors.
 */