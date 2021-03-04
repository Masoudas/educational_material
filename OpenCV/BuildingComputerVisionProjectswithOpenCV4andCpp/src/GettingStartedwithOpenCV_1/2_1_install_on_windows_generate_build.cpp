/**
* Brace yourself, this is going to be long and detailed. Any mistakes would result in linker not being
* able to find the .libs, or run-time not being able to find the 'dll'.
* 
* First, we should decide on the platfrom, and configuaration mode. We have two platforms:
*	- Win32: This is equivalent to x86, meaning 32 bit memory.
*	- x64: This is the 64 bit version, and we usually shoot for this one.
* 
* The configuaration mode is important, so that if we're in the debug or release mode, we need to link to 
* the proper version of each, otherwise, MSVC throws linkage errors.
* 
* As a reminder for the future, linkage errors are those errors the VS throws when it says it cannot find 
* a symbol, like:
* """""""""""""""""""""""""""""
* Error	LNK2019	unresolved external symbol "void __cdecl cv::imshow(class std::basic_string<char,struct 
* std::char_traits<char>,class std::allocator<char> > const &,class cv::debug_build_guard::_InputArray 
* const &)" (?imshow@cv@@YAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV_InputArra
* y@debug_build_guard@1@@Z) referenced in function main	
* """""""""""""""""""""""""""""
* 
* So here are the steps:
*	1- Download the latest repo of opencv FROM github. The nonsense on the opencv website does not work.
*	2- Download the contrib module from github as well.
*	3- Now, create a build folder, and a destination folder, the latter preferably on c:\ 
	   (like c:\opencv-4.5.1)
*	4- Open CMake GUI and set the path to source and build folder. Make first configuration.
*	5- The CMake options now appear, and we need to play with a couple of them:
*		-	install prefix: Find the install prefix, and set it to the destination folder on drive c
*		-	extra modules path: Set this path to the MODULE SUBFOLDER of the contrib repo, not the root
*			folder of it.
*		-	build world: In the BUILD options, set BUILD_opencv_world. This baby creates only one lib
*			called 'opencv_world.lib', which is easier to link against than making a separate lib for
*			each module (like highgui, core, etc.) Believe me!
*		-	Possibly remove build for Java or Python if not desired.
*	6-	At this point, click configure one more time, and then generate.
* 
* And the first part of the build is complete.
*/