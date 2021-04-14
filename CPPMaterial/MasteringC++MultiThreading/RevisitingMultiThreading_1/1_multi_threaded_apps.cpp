/**
 * In its most basic form, a multithreaded application consists of a singular process with two or more threads. 
 * These threads can be used in a variety of ways; for example, to allow the process to respond to events in an 
 * asynchronous manner by using one thread per incoming event or type of event, or to speed up the processing of 
 * data by splitting the work across multiple threads. 
 * 
 * Examples of asynchronous responses to events include the processing of the graphical user interface (GUI) and 
 * network events on separate threads so that neither type of event has to wait on the other, or can block events 
 * from being responded to in time. Generally, a single thread performs a single task, such as the processing of 
 * GUI or network events, or the processing of data. 
 */