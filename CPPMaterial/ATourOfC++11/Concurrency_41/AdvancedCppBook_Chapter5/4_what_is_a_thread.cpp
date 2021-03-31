/**
* When we talk about threads, we mean the thread of execution. This is an abstraction of the operating system, 
* which allows us to perform several tasks simultaneously. Remember that the entire program executes in a 
* separate process. The operating system allocates the address space, processor registers, and some 
* additional resources for the process. All of the worker threads are created within the process and share 
* the same resources. Each process has at least one thread that executes the main() function. We can create a 
* new thread for execution and assign a beginning function that will be the starting point of this thread.
* (Me: by main function we mean main function executed by thread, not the int main())
* 
* Note: As we may recall when reading the Java book by Schildt, a CPU has a number of cores, and in modern
* systems a core can execute two threads simultaneously. Note however that we can create as many threads as
* we desire in our programs, and there's no limit on that.
* 
* The address space and registers of the processor are called Thread Context. When the OS interrupts the 
* thread's work, it must store the context of the current thread and load the context of the next one.
* (Me: Again, as we may recall in Java, the execution of a thread with the same priority is ALWAYS halted to
* make room for continued execution of other threads. So, this is not something that necessarily depends on
* how we write our code.)
* 
*/