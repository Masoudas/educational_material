/**
* As we may recall, with cmake, we needed three lines of code to jump start the project:
* 1-	Defining the minimum version using 'cmake_minimum_required'
* 2-	Defining the project, using 'project(project_name)'
* 3-	Defining a target using 'add_executable(executable_name files)'
* 
* To create a library target, we need to use the 'add_library' function. Moreover, we can link the library with the
* executable using 'target_link_libraries(target libraryies)'. As we may recall, we need to use the SHARED or STATIC
* options to indicate whether we want the created library to be dynamic or static.
* 
*/