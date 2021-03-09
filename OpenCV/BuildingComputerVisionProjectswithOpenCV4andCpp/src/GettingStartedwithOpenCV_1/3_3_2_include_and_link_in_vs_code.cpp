/**
 * Now, the second part of this long journey is to define the inclusion and linkeage path for VS. Recall that as we
 * discussed on gcc fundamentals:
 * 
 *  - header inclusion happens through the -I option of g++
 *  - linkeage happens thtough the -L option of g++.
 * 
 * As we have guessed, we need to add these options manually for the debugger (bugger!) The way to do this as we
 * discussed on gcc discussion is:
 *  - Open the task.json of vs code
 *  - find the args section.
 *  - Now, assuming the headers are at '/usr/local/include' and libs are at '/usr/local/lib', add the following two
 *    lines to the args:
 *      -   '-I', '/usr/local/include'
 *      -   '-L', '/usr/local/lib'
 * 
 * Now, these are for the compiler. We also need to add the include header for the intellisense, and VS Code purposes.
 * This feat is accomplished by adding the include path to the inclusion path of c_cpp_properties.json of vs code.
 * 
 * After this, we'll see if you break eggs again!
 *
 */