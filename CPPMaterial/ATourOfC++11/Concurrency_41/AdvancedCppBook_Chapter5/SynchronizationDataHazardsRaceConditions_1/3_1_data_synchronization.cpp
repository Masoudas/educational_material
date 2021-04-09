/**
* To prevent races and data hazards, there is a shared data locking mechanism where one of the streams intends to change or 
* read these data. This mechanism is called resource synchronization. For synchronization, we need to allocate pieces of 
* code that change or read shared resources. Such pieces of code are called critical sections. Synchronization consists of 
* blocking critical sections when one of the threads enters it. Other threads that also intend to execute the code of this 
* critical section will be blocked. When the thread executing the critical section leaves it, the lock is released. Then, 
* the story will repeat with the next thread.
* 
* Consider the example of incrementing a value with two threads. Remember that we have threads A and B and have a variable 
* that is equal to 0. Thread A starts the increment:
* 
*	-	Enters the critical section and locks it.
*	-	Reads the value of the variable (var = 0).
*	-	Increments it (tmp = 1).
*	-	Gets interrupted by the OS.
* 
* Thread B starts the increment:
*	-	Tries to enter the critical section; it's locked, so the thread is waiting.
* 
* Thread A continues the increment:
*	-	Writes the new value (var = 1).
* 
* Thread B continues the increment:
*	-	Enters the critical section and locks it.
*	-	Reads the value of the variable (var = 1).
*	-	Increments it (tmp = 2).
*	-	Writes the new value (var = 2).
* 
* After the completion of both threads, the variable contains the correct result. Thus, synchronization ensures that 
* shared data will not be damaged.
* 
* Highlighting critical sections and anticipating the possible consequences of non-synchronized access is a very difficult 
* task. Because excessive synchronization negates the very essence of multithreaded work. If two or three threads work on 
* one critical section rather quickly, however, there can be dozens of threads in the program where all of them will be 
* blocked in the critical section. This will greatly slow down the program.
*/