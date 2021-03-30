/**
* When creating a project, we can use the 'FIND_PACKAGE' command of opencv to find a package such as opencv. To find
* a package, either a predefined module should have been shipped with cmake (which has a corresponding .cmake file
* inside the cmake modules folder,) or we're going to provide one for it. In the case of opencv, we need to have
* installed opencv, because there's no opencv_config.cmake shipped with opencv. We particularly need to have set
* the variable OpenCV_DIR, and have added the libraries to the path. Once this is done, the find package module
* will find the config file shipped with the installed opencv folder, and adds it to our project.
*
* Note that the syntax for the FIND_PACKAGE command is as follows:
* 'FIND_PACKAGE(OpenCV VERSION REQUIRED module_names)'
* where VERSION is a typical opencv version, REQUIRED means this package is required for this project. We can
* further specify which modules of opencv we want in our project. For example:
* 1- FIND_PACKAGE(OpenCV 4.0.0 REQUIRED)
* 2- FIND_PACKAGE(OpenCV 4.0.0 REQUIRED core imgproc)
*
* In 1, we download every single module of opencv. In the second one, we only download the core and imgproc modules.
*
* The command 'include_directories' is used for including the directory of opencv and building it, using its
* CMakeLists.txt file.
*
* Now, after we've compiled the library, we need to do two things:
* 1-	We need to provide a path for the linker to search for the files
* 2-	We need to provide the path to the include folder of the project, to add the header files.
*
* To do the second one, we know that we need only to use target_link_libraries. For the first one, the command,
* link_directories(path) tells the linker to include path in its search too. Easy!
*
* Note that when the package is installed, CMAKE provides us with the following variables to work with for CMAKE:
* -	OpenCV_VERSION: OpenCV version.
* - OpenCV_INCLUDE_DIRS: The path where the root folder of OpenCV (including its Lists file) resides. This is the
*						 path that has to be included to build the library from our project.
* - OpenCV_LIB_DIR:	For where the openCV (shared) libraries reside.
* - OpenCV_LIBS:	This is the path for the library of openCV. In other words, this is the path where the header files
*				reside. We should use this path with the target_link_libraries command.
*
*/