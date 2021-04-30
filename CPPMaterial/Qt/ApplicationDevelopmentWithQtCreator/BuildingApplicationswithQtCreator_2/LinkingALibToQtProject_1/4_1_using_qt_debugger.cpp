/**
 * In linux, the qt creator works out of the box with the debugger of gcc, which as we may recall is gdb. However, 
 * in Windows, we might want to make make sure that with MSVC, we've installed command line debugger or CDB for
 * MSVC.
 * 
 * 
 * When debuggin:
 *  -   Use F5 to step over the break point
 *  -   Step over (execute current line, and then go to the next) using F10
 *  -   Step into (enter function that's going to be called and then stops) using F11
 *  -   There's also a menu of threads, so you can see which thread is running or has stopped.
 *  -   With some debuggers, we can move the arrow to different lines in the calling function to skip one or more 
 *      lines of code, or rewind the execution to rerun a segment of code again.
 */