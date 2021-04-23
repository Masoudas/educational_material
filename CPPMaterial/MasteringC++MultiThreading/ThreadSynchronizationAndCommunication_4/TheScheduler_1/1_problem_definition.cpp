/**
 * A good example of multithreading with a significant amount of synchronization and communication between 
 * threads is the scheduling of tasks. Here, the goal is to accept incoming tasks and assign them to work 
 * threads as quickly as possible.
 * 
 * In this scenario, a number of different approaches are possible. Often one has worker threads running in 
 * an active loop, constantly polling a central queue for new tasks. Disadvantages of this approach include 
 * wasting of processor cycles on the said polling, and the congestion which forms at the synchronization 
 * mechanism used, generally a mutex. Furthermore, this active polling approach scales very poorly when the 
 * number of worker threads increase.
 * 
 * Ideally, each worker thread would wait idly until it is needed again. To accomplish this, we have to 
 * approach the problem from the other side: not from the perspective of the worker threads, but from that 
 * of the queue. Much like the scheduler of an operating system, it is the scheduler which is aware of both 
 * the tasks which require processing as well as the available worker threads.
 * 
 * In this approach, a central scheduler instance would accept new tasks and actively assign them to worker 
 * threads. The said scheduler instance may also manage these worker threads, such as their number and 
 * priority, depending on the number of incoming tasks and the type of task or other properties.
 * 
 * At its core, our scheduler or dispatcher is quite simple, functioning like a queue with all of the 
 * scheduling logic built into it, as seen in Fig1.
 */