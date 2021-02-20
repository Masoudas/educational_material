/**
* Installing opencv on Windows should be an easy task. Assuming that we don't want to use the exe file on the 
* opencv website, we use the git version. Note that we need an include folder, and then the dlls to link to
* at run-time. To this end:
* 
* 1- Download the git repo of openCV
* 2- cmake it, to have the VS solution.
* 3- Go into the solution with administrator privilege. Build the solution, and particularly install it. Note that
*	the build should be in Release (I guess, because we don't want to Debug OpenCV)
* 4- Now, put the include and dlls in a path, like C:\OpenCV-4.5.1. What should we put here?
*	-	The include headers, which are found under
*	-	The dlls and binaries, which are found under
*	-	The opencv_config.cmake files, which are what we require to use opencv in other cmake projects.
* Now, in Windows, all of this would be in the 'install' folder, but I need to run the install project to access
* them.	
* 5- Now, in the project, in both the debug and release modes, go to project properties, and ONLY in the 
* 'VC++ Directories', add the path to the include folder, and then the dlls. Note that the include folder should
* be given, so that the inclusion of opencv headers look something like this:
* 
* #include "opencv2/core.hpp"
* 
* and not:
* 
* #include "core.hpp" "This version has added the opencv2 folder too!
*/