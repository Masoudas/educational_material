/**
 * Essentially, to the operating system (OS), a process consists of one or more threads, each thread 
 * processing its own state and variables. One would regard this as a hierarchical configuration, with the 
 * OS as the foundation, providing support for the running of (user) processes. Each of these processes then
 * consists of one or more threads. Communication between processes is handled by inter-process communication
 * (IPC), which is provided by the operating system.
 * 
 * Essentially, threads are nested in a process, which is nested (executed) by the OS, which itself is nested
 * in the hardware.
 * 
 * Each process within the OS has its own state, with each thread in a process having its own state as well 
 * as the relative to the other threads within that same process. While IPC allows processes to communicate 
 * with each other, threads can communicate with other threads within the process in a variety of ways, 
 * which we'll explore in more depth in upcoming chapters. This generally involves some kind of shared memory 
 * between threads.
 * 
 * ME: So we must make a distinction:
 *  -   Task: A task is a set of program instructions that are loaded in memory.
 *  -   Process: Consists of one or more threads. A process must contain at least one thread to be executed
 *      by CPU. It's equivalent to a computer program/
 *  -   Thread: A set of instructions to be executed inside the process. A thread is a basic unit of CPU 
 *      utilization, consisting of a program counter, a stack, and a set of registers
 * 
 * From another point of view:
 * A thread is a scheduling concept, it's what the CPU actually 'runs' (you don't run a process). A process 
 * needs at least one thread that the CPU/OS executes. A process is data a organizational concept. Resources 
 * (e.g. memory for holding state, allowed address space, etc) are allocated for a process.
 * 
 * 
 */ 