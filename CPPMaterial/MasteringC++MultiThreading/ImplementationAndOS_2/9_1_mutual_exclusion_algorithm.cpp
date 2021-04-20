/**
 * Mutual exclusion is the principle which underlies thread-safe access of data within a multithreaded 
 * application. One can implement this both in hardware and software. The mutual exclusion (mutex) is the 
 * most elementary form of this functionality in most implementations.
 * 
 * Hardware:
 * The simplest hardware-based implementation on a uniprocessor (single processor core), non-SMT system is 
 * to disable interrupts, and thus, prevent the task from being changed. More commonly, a so-called busy-wait 
 * principle is employed. This is the basic principle behind a mutex--due to how the processor fetches data, 
 * only one task can obtain and read/write an atomic value in the shared memory, meaning, a variable sized the
 * same (or smaller) as the CPU's registers. 
 * 
 * When our code tries to lock a mutex, what this does is read the value of such an atomic section of memory, 
 * and try to set it to its locked value. Since this is a single operation, only one task can change the 
 * value at any given time. Other tasks will have to wait until they can gain access in this busy-wait cycle, 
 * as shown in Fig7.
 * 
 * Software:
 * An algorithm like Dekkard's can be used as an example. Me: It's basically a while loop and process ID
 * checking.
 * 
 * However, a major disadvantage of software-based mutual exclusion algorithms is that they only work if 
 * out-of-order (OoO) execution of code is disabled. OoO means that the hardware actively reorders incoming 
 * instructions in order to optimize their execution, thus changing their order. Since these algorithms 
 * require that various steps are executed in order, they no longer work on OoO processors.
 */
