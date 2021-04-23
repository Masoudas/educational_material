/**
 * Before the C++ 2011 (C++11) standard, many different threading implementations were developed, many of 
 * which are limited to a specific software platform. Some of these are still relevant today, such as 
 * Windows threads. Others have been superseded by standards, of which POSIX Threads (Pthreads) has become 
 * the de facto standard on UNIX-like OSes. 
 * 
 * Many libraries were developed to make cross-platform development easier. Although Pthreads helps to make 
 * UNIX-like OS more or less compatible, one of the prerequisites to make software portable across all major 
 * operating systems, a generic threading API, is needed. This is why libraries such as Boost, POCO, and Qt 
 * were created. Applications can use these and rely on the library to handle any differences between 
 * platforms.
 * 
 * Me: One thing I don't understand here is that the headers for threads are the same and standardized. So
 * how come we say pthread is only for unix, and Windows thread for Windows? I think possiblt to fine grain
 * we need to directly access the libraries.
 */