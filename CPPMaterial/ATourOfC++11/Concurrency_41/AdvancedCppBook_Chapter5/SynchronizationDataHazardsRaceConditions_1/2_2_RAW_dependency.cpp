/**
* A RAW dependency occurs when one thread calculates the value that is used by another thread. For example, Thread A should 
* do its job and write the results to a variable. Thread B must read the value of this variable and do its job. In 
* pseudocode, this looks as follow:

Thread A: a = doSomeStuff();	// Write to a by doing it's stuff.
Thread B: b = a - doOtherStuff();	// Read a, then do other stuff.

* Difficulties will arise if Thread B executes first. It will lead to Thread B reads an invalid value. The order of the 
* execution of threads should be strictly guaranteed. Thread B must read the value of the variable, but only after Thread 
* A has written it. Otherwise, it will lead to undefined behavior.
* 
*/