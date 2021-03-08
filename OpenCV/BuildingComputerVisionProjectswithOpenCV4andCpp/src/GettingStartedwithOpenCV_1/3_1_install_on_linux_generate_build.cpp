/**
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
 * Question: How can we generate opencv for x86 or x64 architecture? What about config modes? Should we even ask this
 * question on linux? Well, unlike Windows, there's no visual studio where I can just go and change the architecture 
 * and config mode. At least in terms of the config mode, if needed, we can change the config mode using the config
 * flag from the command line.
 */