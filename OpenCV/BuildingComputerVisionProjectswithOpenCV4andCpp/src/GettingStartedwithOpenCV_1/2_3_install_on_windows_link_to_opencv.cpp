/**
* Now comes the controversial part. It seems doing two things is enough, both of which must be done for
* the PROJECT we're working on, in the properties menu of the project:
* 
* 1-	Add include and library path: In General>VC++ directories, add the path to include and lib folder
*		of opencv in include and library folders of the project.
* 2-	Add libs directly:  Now, having done that, we need to specify the libraries for the linker explicitly.
*		This must be done by going in Linker>Input>Additional Dependencies.
* 
* Now, some people over the Internet have suggested adding the path to libs at Linker>General, add path,
* and then setting to 'YES' the option "Use Library Dependency Inputs", but things seem to be alright 
* without them too!
* 
* As reminder we should be careful which library (and path) we link to. For example, if our project is
* in x86 and debug, then in the destination we must link against x86/vc16/lib and opencv-world451d.dll,
* where the stress is on 'd' here. In all cases, we need to add the path to the bin folder to our 'PATH'
* variable, using the environment setting of Windows.
*/