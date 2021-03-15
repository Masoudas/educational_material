/**
* At this point, it's time to build the actual object files, and dlls and libs. Before we proceed, we 
* should note three things as a reminder that are generated after the built process concludes:
*	1-	There's an include path generated after built, which contains the header files
*	2-	There's a lib folder, which the MSVC linker uses to link against.
*	3-	Then there's the dll files, which are in the lib folder of installed opencv, which are used at
*		run-time, and contain the actual binaries.
* 
* Now, we need to build the solution in VS. So here's what we need to do:
*	1-	Decide on the built mode (debug or release). Choose it on the top and build. If we decide the
*		debug mode, the generated lib files would have d, like opencv_worldxxxd.lib, where xxx is the
*		version.
*	2-	Run the ALL-BUILD project in the cmake folder first.
*	3-	When this finished, run the install project, we can see that the installation process takes
*		place in the folder we set in CMAKE.
* 
* If you want my opinion, build for both x86 and x64, and in both config modes debug and release. This is
* because often we want to work in the debug mode, and not having the debug mode causes compilation errors.
*/