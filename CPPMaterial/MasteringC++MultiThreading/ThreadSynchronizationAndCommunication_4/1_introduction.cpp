/**
 * Topics covered in this chapter include the following:
 *  -   Using mutexes, locks, and similar synchronization structures
 *  -   Using condition variables and signals to control threads
 *  -   Safely passing and sharing data between threads
 * 
 * The central problem with concurrency is that of ensuring safe access to shared resources even when 
 * communicating between threads. There is also the issue of threads being able to communicate and 
 * synchronize themselves.
 * 
 * What makes multithreaded programming such a challenge is to be able to keep track of each interaction 
 * between threads, and to ensure that each and every form of access is secured while not falling into the 
 * trap of deadlocks and data races.
 */