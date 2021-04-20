/**
 * The concept of a process and a shared memory space between the threads contained within the said process 
 * is at the very core of multithreaded systems from a software perspective. Though the hardware is often 
 * not aware of this--seeing just a single task to the OS. However, such a multithreaded process contains 
 * two or many more threads. Each of these threads then perform its own series of tasks.
 * 
 * In other implementations, such as Intel's Hyper-Threading (HT) on x86 processors, this multithreading is 
 * implemented in the hardware itself, where it's commonly referred to as SMT (to be discussed). When HT is 
 * enabled, each physical CPU core is presented to the OS as being two cores. The hardware itself will then 
 * attempt to execute the tasks assigned to these so-called virtual cores concurrently, scheduling 
 * operations which can use different elements of a processing core at the same time. In practice, this can 
 * give a noticeable boost in performance without the operating system or application requiring any type of 
 * optimization. (Me: When I was buying a laptop at CENTURI, I recall that the CPUs said to have 8 cores and
 * hyper threading, which doubled their number of cores! So this is it. Hyper threading views each core as
 * two cores! And this is multithreading regardless of how we write code.)
 * 
 * The OS can of course still do its own scheduling to further optimize the execution of task, since the 
 * hardware is not aware of many details about the instructions it is executing.
 * 
 * Having HT enabled looks like the visual format shown in Fig6, where we see the instructions of four 
 * different tasks in memory (RAM). Out of these, two tasks (threads) are being executed simultaneously, with 
 * the CPU's scheduler (in the frontend) attempting to schedule the instructions so that as many instructions 
 * as possible can be executed in parallel. Where this is not possible, so-called pipeline bubbles (in white) 
 * appear where the execution hardware is idle.
 * 
 * Me: I guess the point here is that somehow hyperthreading allows for more than once thread to be executed
 * per CPU cycle, by I guess somewhat mixing the instructions of two threads.
 * 
 */