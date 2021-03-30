/**
* We shall distinguish between concurrency and parallelization.
* 
* Concurrency, indicates that more than one task will be completed in a given period. How these tasks are
* accomplished is irrelevant. For example, if three people are using a computer together, their task is
* concurrent. However, they can use it one by one and terminate, or they can use it periodically. In the 
* philosophers' dinner, if each picks two chopsticks, eats one bite, and then alternate, then we have a case
* of concurrency, but not parallelism.
* 
* Parallelism occurs when several tasks are performed simultaneously. The tasks work in parallel due to 
* hardware capabilities. The best example of parallelism is a multi-core processor. For parallel execution, 
* the tasks are divided into completely independent subtasks that are performed in different processors' 
* cores. After that, the result of the execution can be combined. This will be the case if we had three 
* computers, and three people were working on them (me: probably to attain a shared task.) In the philosophors'
* dinner, if we gave each of them an extra chopstick, then we'd have a case of parallelism.
* 
* Me: We could argue that parallelism is a form of concurrency.
*/