/**
 * Me: Let's summarize this discussion as follows:
 *  -   Multiprogramming – A computer running more than one program at a time (like running Excel and Firefox 
 *      simultaneously).
 *  -   Multiprocessing – A computer using more than one CPU at a time.
 *  -   Multitasking – Tasks sharing a common resource (like 1 CPU). It's an extention of multiprocessing.
 *  -   Multithreading is an extension of multitasking.
 * Fig 5 illustrates this perfectly. We see that multi-processing is using multiple CPUs in a computer. 
 * Multi-tasking is time sharing between different tasks on ONE CPU. Multi-threading is sharing a CPU among
 * different units of ONE task, possibly, or different tasks. Many people use task and process interchangeably.
 * Once again, process is OS level, whereas threads are something we define in our program for a process (or
 * task.)
 * 
 * Over the past decades, a lot of different terms related to the way tasks are processed by a computer have 
 * been coined and come into common use. Many of these are also used interchangeably, correctly or not. An 
 * example of this is multithreading in comparison with multiprocessing.
 * 
 * Here, the latter means running one task per processor in a system with multiple physical processors, while 
 * the former means running multiple tasks on a singular processor simultaneously, thus giving the illusion that
 * they are all being executed simultaneously (Me: Multi threading should be regarded as something we do in a 
 * program. We can't multiprocess in a program, because our entire program is a single process. Hence, multi 
 * threading is time slicing, whereas multi processing is core slicing. Multi processing is done at the CPU
 * level.) (ME: Recall that CPU only understands threads, and not processes. It executes thread instructions 
 * only.)
 * 
 * Another interesting distinction between multiprocessing and multitasking is that the latter uses 
 * time-slices in order to run multiple threads (me: of tasks) on a single processor core. This is different 
 * from multithreading in the sense that in a multitasking system, no tasks will ever run in a concurrent 
 * fashion on the same CPU core, though tasks can still be interrupted. 
 * Me: I don't understand this last sentence!
 */