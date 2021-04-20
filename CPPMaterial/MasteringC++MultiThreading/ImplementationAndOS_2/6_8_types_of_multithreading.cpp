/**
 * Like multiprocessing, there is not a single implementation, but two main ones. The main distinction 
 * between these is the maximum number of threads the processor can execute concurrently during a single 
 * cycle (me: I think we're talking about hyper threading here.). The main goal of a multithreading 
 * implementation is to get as close to 100% utilization of the processor hardware as reasonably possible. 
 * Multithreading utilizes both thread-level and process-level parallelism to accomplish this goal. 
 * 
 * The are two types of multithreading:
 *  -   Temporal multithreading
 * Also known as super-threading, the main subtypes for temporal multithreading (TMT) are coarse-grained and 
 * fine-grained (or interleaved). The former switches rapidly between different tasks, saving the context of 
 * each before switching to another task's context. The latter type switches tasks with each cycle, 
 * resulting in a CPU pipeline containing instructions from various tasks from which the term interleaved is 
 * derived. 
 * 
 * The fine-grained type is implemented in barrel processors. They have an advantage over x86 and other 
 * architectures that they can guarantee specific timing (useful for hard real-time embedded systems) in 
 * addition to being less complex to implement due to assumptions that one can make.
 * 
 *  -   Simultaneous multithreading (SMT)
 * SMT is implemented on superscalar CPUs (implementing instruction-level parallelism), which include the 
 * x86 and ARM architectures. The defining characteristic of SMT is also indicated by its name, specifically, 
 * its ability to execute multiple threads in parallel, per core. Generally, two threads per core is common, 
 * but some designs support up to eight concurrent threads per core. The main advantage of this is being 
 * able to share resources among threads, with an obvious disadvantage of conflicting needs by multiple 
 * threads, which has to be managed. Another advantage is that it makes the resulting CPU more energy 
 * efficient due to a lack of hardware resource duplication. 
 * 
 * Intel's HT technology is essentially Intel's SMT implementation, providing a basic two thread SMT engine 
 * starting with some Pentium 4 CPUs in 2002.
 */
