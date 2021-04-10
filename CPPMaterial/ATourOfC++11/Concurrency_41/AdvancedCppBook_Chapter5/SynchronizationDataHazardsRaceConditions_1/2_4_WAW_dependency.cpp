/**
* A WAW dependency occurs when several threads change the value of the same variable, and some thread reads for its 
* calculations. For example, Thread A executes its job and writes the results to a variable. Thread B reads the value of 
* the variable and executes its job. Thread C executes its job and writes the results to the same variable. In pseudocode, 
* this looks as follows:

Thread A: a = doSomeStuff();
Thread B: b = a - doOtherStuff();
Thread C: a = doNewStuff();

* Difficulties will arise if Thread C executes before threads A and B. This leads to Thread B reads the value that it is 
* not expected to be read. The order of the execution of threads should be strictly guaranteed. Thread C must write a new 
* value to a variable, but only after Thread A has written its value and Thread B has read it.
*/