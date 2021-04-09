/**
* There is another mechanism for synchronizing the work of threads – event synchronization. This means the synchronization 
* of the work of the threads when one of them suspends its work until the other thread signals the occurrence of some 
* event.
* 
* (me: I think in essense, we exchange messages between threads, and synchronize their actions. This means one thread reads
* the data when another thread generates an event saying its job is done.)
* 
* For example, there's Thread A, which receives a message from another process. It writes the message to the queue and waits 
* for new messages. There is another thread, Thread B, that processes these messages. It reads messages from the queue and 
* performs some actions on them. When there are no messages, Thread B is sleeping.
* 
* When Thread A receives a new message, it wakes up Thread B and processes it
*/