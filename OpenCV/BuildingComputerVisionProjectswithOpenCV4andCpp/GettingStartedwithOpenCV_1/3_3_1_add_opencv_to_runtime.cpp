/**
 * As always, we get to the challenging part of linking the libraries. In this instance, we're interested in
 * inclusion and linkeage in VS Code, using g++. Before we do anything, to allow the run-time to find opencv
 * libraries, we need to define them for the runtime of Linux (the thing that deals with ELF files, which I'm not
 * aware of at this point.) Essentially, this is what binds the application to system and other libraries at runtime.
 * 
 * To define a new path for the run-time linker, we need to do two things:
 *  -   define a .conf file with the name of the project in the '/etc/ld.so.conf.d/' folder that contains the path
 *      to the libraries.
 *  -   run the 'ldconfig -v' command as superuser to update the linker of linux.
 * 
 * Now, it's interesting to note that why this problem happens. It's essentially because the linker does not search
 * inside '/usr/local/bin' (where we've installed our opencv library.) This is kind of odd, but understanble, given
 * the fact that perhaps the OS does not want to look inside the libraries we've compiled!
 * 
 * In any case, we need to add an 'opencv.conf' in the aforementioned folder, and then sudo run the ldconfig command,
 * and this concludes the inclusion of link path for the system.
 * 
 * Now, once we've done this, the opencv libraries can be detected at the linkeage stage. Therefore, we can use the
 * '-l' option (rather than '-L'. See Discussion about gcc compiler in Embedded stuff) to link at run-time.
 */