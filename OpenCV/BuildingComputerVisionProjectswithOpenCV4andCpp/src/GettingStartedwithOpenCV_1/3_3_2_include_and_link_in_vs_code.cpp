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
 * Setting the launch file: 
 * So, the launch file is the one that's used to actually run the program, in particular. Now, consider the following 
 * path is set in the task as the folder for placement of the greated binary:
 * 
 *  - 'o',  ${workspaceFolder}/build/${fileBasenameNoExtension}"
 * 
 * This would imply that we place the generated binary in the workspace folder (project root), in a folder called
 * build, and the binary would have the exact same name as the filename without its extension. Therefore, if the 
 * root of the project is '/home/masoud/opencv_proj,' and the file name is 'main.cpp,'it will be placed in
 * '/home/masoud/opencv_proj/build/main.' Now, the launch file tries to execute the binary, but the default path there
 * is "${fileDirname}/${fileBasenameNoExtension}," which is not the path to the src folder we just defined. Therefore,
 * we need to go inside the launch json, and change the field "program" to the path we defined and it shall run the
 * program for us.
 */
