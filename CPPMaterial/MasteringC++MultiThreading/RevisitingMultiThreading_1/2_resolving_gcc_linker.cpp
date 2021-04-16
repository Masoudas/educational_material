/**
 * As we may recall from our discussion on embedded programming, the gcc linker DOES NOT automatically link to
 * all libraries by default.
 * 
 * The pthread library then has to be linked manually. Recall that threads are not fascilities of C++, but rather
 * system dependent. Therefore, the pthread which is what we seek IS NOT part of gcc, but rather part of the
 * libraries linux provides for us, which are in /usr/lib/x86_64-linux-gnu/libpthread.so. So, that's that.
 * 
 *  The command line addition commands are
 *
 * $ gcc -lpthread      // Links shared or dynamic as we may recall.
 * 
 * Finally, recall that the actual files libpthread.so, libpthread.a
 */