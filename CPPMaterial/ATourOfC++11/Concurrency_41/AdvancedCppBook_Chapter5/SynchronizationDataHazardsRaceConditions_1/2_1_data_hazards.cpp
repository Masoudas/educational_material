/**
* Sometimes, there are situations where the data is damaged, and this leads to undefined program behavior or abnormal 
* termination. Such damage to data, as a result of race conditions or simply wrong design, are known as data hazards. In 
* general, this term implies that the final result of a piece of work depends on the order of the thread's execution. If 
* different threads work with shared data or global variables, it may happen that, due to an incorrect order of task 
* execution by different threads, the result will vary from time to time. This happens due to the dependencies between the 
* data being multi-threaded. Such dependency issues are conditionally divided into three groups:
* 
*	-	A true dependency: Read After Writing (RAW)
*	-	An anti-dependency: Write After Reading (WAR)
*	-	An output dependency: Write After Writing (WAW)
* 
* We shall discuss each case next.
*/