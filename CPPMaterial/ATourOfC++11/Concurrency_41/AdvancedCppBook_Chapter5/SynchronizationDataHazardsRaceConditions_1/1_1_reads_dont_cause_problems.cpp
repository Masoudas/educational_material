/**
* me: The way threads work are like interrupts in an embedded system. Hence, when a thread is over a resource (let's
* say memory) and another threads wants to access that memory address, the scheduler pulls the current thread back,
* and allows the recent thread to access that variable. Consequently, a simple read of a resource by several threads
* does not cause any problem.
* 
* The key challenge of multithreaded programming is knowing how the threads work with shared data. Shared data, also 
* known as resources, are not only variables, but also file descriptors and environment variables, and even Windows 
* registries. For example, if the threads just read the data, then there are no problems and **no synchronization** is 
* required. However, if at least one of the threads edits the data, race conditions could arise. Usually, the operations 
* on the data are not atomic, that is, they require several steps. Even the simplest increment operation of a numeric 
* variable is performed in the following three steps:
*	(1)	Read the value of the variable (me: in a temp)
*	(2)	Increment it (me: increment the temp)
*	(3)	Write the incremented value 
* 
* Due to the interruptions of OS, the thread can be stopped before it completes the operation. For example, we have 
* threads A and B and have a variable that is equal to 0. 
* Thread A starts the increment:
*	-	Reads the value of the variable (var = 0).
*	-	Increments it (tmp = 1).
*	-	Gets interrupted by the OS.
* Then thread B starts the increment:
*	-	Reads the value of the variable (var = 0).
*	-	Increments it (tmp = 1).
*	-	Writes the new value (var = 1).
*	-	Gets interrupted by the OS.
* Thread A continues the increment:
*	-	Writes the new value (var = 1).
* 
* We can see in the above example that, instead of having a value of 2 in the variable, we now have a one in it.
* Let's go back to the philosophers' dinner analogy. The original issue was that one philosopher had only one 
* chopstick. If all of them are hungry, then they will hurry to grab two chopsticks. The first philosopher who grabs 
* two chopsticks will be the first to eat, and the others must wait. They will race for the sticks.
* 
*/