/**
* A WAR dependency occurs when one thread changes the data that is used by another thread. For example, Thread A must read 
* the value of a variable and do its job. After that, Thread B should do its job and write the results to a variable. In
* pseudocode, this looks as follows:

Thread A: b = a - doSomeStuff(); // Read a, do some stuff.
Thread B: a = doOtherStuff();	// Write to a.

* Difficulties will arise if Thread B executes first. It will lead to Thread B changing the value before Thread A reads it. 
* The order of the execution of threads should be strictly guaranteed. Thread B should write the new value to a variable 
* only after Thread A reads its value.
*/