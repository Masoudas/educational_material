/**
 * Before proceeding with the build, we need to pre-install the following set of libraries, which are going to be
 * needed for the highgui module of opencv:
 * sudo apt install gtk libcanberra-gtk-module libcanberra-gtk3-module
 * 
 * The build generation process is the same as that of Windows, including setting the build flags. There, we need 
 * only to consult the documentation on Windows. 
 * 
 * The only difference with the Windows build process in Linux is that in Linux, instead of creating solutions, we're
 * going to generate make build scripts, which we then have to run from the command line with the usual formulation
 * of make files.
 * 
 * Note on the install prefix: On linux, we can set the installation path (like in Windows,) using the install prefix
 * option. Whether we want it on '/usr/local' or more local folder is a question of taste.
 * 
 * Now, over the Internet, people have suggested setting the following cmake flags, and by not setting them, possibly
 * some weird debug errors may occur:
 * 
 *  -   BUILD_TIFF=ON 
 *  -   WITH_CUDA=OFF 
 *  -   ENABLE_AVX=OFF
 *  -   WITH_OPENGL=ON 
 *  -   WITH_OPENCL=OFF 
 *  -   WITH_IPP=OFF 
 *  -   WITH_TBB=ON 
 *  -   BUILD_TBB=ON 
 *  -   WITH_EIGEN=OFF 
 *  -   WITH_V4L=OFF 
 *  -   WITH_VTK=OFF
 *  -   BUILD_TESTS=OFF 
 *  -   BUILD_PERF_TESTS=OFF
 *
 * Question: Should we set the configuration mode? Well, over the internet, people have suggested setting this flag
 * in CMake to RELEASE:
 *  -   CMAKE_BUILD_TYPE
 * At this point in time, I still don't know whether or not we need build in debug mode for debug purposes or not.
 * 
 * 
 * Question: How can we generate opencv for x86 or x64 architecture? Is it even needed? Now, this as we recall has
 * to be done in CMake, 
 * 
 *
 */