/**
 * Note: As the big guy repeated several times, multi-threading fascilities are OS dependent. In fact, if
 * we checkout the thread header in gcc for example, it only exists in the include folder. However, libpthread
 * is implemented as part of the system libraries in /usr/lib/x86_64-linux-gnu. Hence, we should be familiar
 * with the multi-threading fascilities of each processor and OS.
 * 
 * The foundation of any multithreaded application is formed by the implementation of the required features 
 * by the hardware of the processor, as well as by the way these features are translated into an API for use 
 * by applications by the operating system. An understanding of this foundation is crucial for developing an 
 * intuitive understanding of how to best implement a multithreaded application.
 */