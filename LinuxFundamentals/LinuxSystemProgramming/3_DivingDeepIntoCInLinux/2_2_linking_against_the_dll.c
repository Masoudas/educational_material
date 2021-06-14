/**
 * As we may recall, for linkeage against a dll, we need to add the path (-L) and then library name (-l) excluding
 * the lib part. Note that the same goes for inclusion (-I)
 * 
 * Example:
 * $ gcc -L${PWD} -lprime is-it-a-prime.c -o is-it-a-prime
 * 
 * Also, recall that the LD_LIBRARY_PATH variable is the variable used by the linker to search for libraries at
 * runtime, so we need to add our non-standard path to it. However, we can use the ld.so.conf.d folder, and then
 * run the ldconfig command as well.
 * 
 * Note that using the ldd program, we can determine which libraries our program depend upon (shared ones of
 * course)
 */
