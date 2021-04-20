/**
 * A number of task-scheduling algorithms exist, each focusing on a different goal. Some may seek to maximize 
 * throughput, others minimize latency, while others may seek to maximize response time. Which scheduler is 
 * the optimal choice solely depends on the application the system is being used for.
 * 
 * For desktop systems, the scheduler is generally kept as general-purpose as possible, usually prioritizing 
 * foreground applications over background applications in order to give the user the best possible desktop 
 * experience. 
 * 
 * For embedded systems, especially in real-time, industrial applications would instead seek to guarantee 
 * timing. This allows processes to be executed at exactly the right time, which is crucial in, for example, 
 * driving machinery, robotics, or chemical processes where a delay of even a few milliseconds could be 
 * costly or even fatal.
 * 
 * The scheduler type is also dependent on the multitasking state of the OS--a cooperative multitasking 
 * system would not be able to provide many guarantees about when it can switch out a running process for 
 * another one, as this depends on when the active process yields.
 * 
 * Starting with Linux kernel 2.6.23, the default scheduler is the Completely Fair Scheduler (CFS), which 
 * ensures that all tasks get a comparable share of CPU time.
 */