/**
* Precompiled headers (and files) are parts of the program that rarely change, hence they can be compiled once and
* then used by the entire projet. Obviously, the C++ compiler provides us with the opportunity to either use the
* precompiled headers, or if we have changed them, recompile them. For example, in MSVC, the option /Y means use
* precompiled headers, /Yc means use precompiled files, etc.
* 
* In MSVC, The precompiled headers used to be put in stdfax.h, but now we create a pch.h file to that end.
* The purpose of the file is to speed up the build process. Options associated with precompiled headers can be
* found at Configuration Properties > C/C++ > Precompiled Headers. Any stable header files, for example Standard 
* Library headers such as <vector>, should be included here. The precompiled header is compiled only when it, or 
* any files it includes, are modified. If you only make changes in your project source code, the build will skip 
* compilation for the precompiled header. (Apparently as the example on the microsoft website shows, we don't need
* to have all the headers gathered in a single file called pch.h. We rather indicate them to the compiler, either
* using CMAKE, or by declaring them in the precompiled headers options).
* 
*/