/**
 * We shall look at the code from a HW and OS point of view.
 * 
 * When we look at the start of the code in the main function, we see that we create a data structure 
 * containing a single (integer) value:
int main(){
    values.push_back(42);
...
 * After the OS creates a new task and associated stack structure, an instance of a vector data structure 
 * (customized for integer types) is allocated on the stack. The size of this was specified in the binary 
 * file's global data section (BSS for ELF).
 * 
 * When the application's execution is started using its entry function (main() by default), the data structure 
 * is modified to contain the new integer value.
 *
 * Next, we created four threads, t1 to t4.
 * 
 * For the OS, this means creating new data structures, and allocating a stack for each new thread. For the 
 * hardware, this initially does not change anything if no hardware-based task switching is used. (Me: the
 * stack is created in the memory allocated to the process, and its pointer is ready to be sent to RAM.)
 * 
 * At this point, the OS's scheduler and the CPU can combine to execute this set of tasks (threads) as 
 * efficiently and quickly as possible, employing features of the hardware including SMP, SMT, and so on.
 * 
 * After this, the main thread waits until the other threads stop executing:

 tr1.join();
 ...
 tr4.join();

 * These are blocking calls, which mark the main thread as being blocked until these four threads (tasks) 
 * finish executing. At this point, the OS's scheduler will resume execution of the main thread.
 * 
 * In each newly created thread, we first output a string on the standard output, making sure that we lock 
 * the mutex to ensure synchronous access:
 
 void threadFnc(int tid) {
    cout_mtx.lock();
    cout << "Starting thread " << tid << ".\n";
    cout_mtx.unlock();

 * A mutex, in essence, is a singular value being stored on the stack of heap, which then is accessed using 
 * an atomic operation. This means that some form of hardware support is required. Using this, a task can 
 * check whether it is allowed to proceed yet, or has to wait and try again (here, the output buffer not 
 * overridden by multiple threads.) 
 * 
 * The rest of the code is the same, except for:
 
int randGen(const int& min, const int& max) {
    static thread_local mt19937 generator(hash<thread::id>() (this_thread::get_id()));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

 * This method is interesting due to its use of a thread-local variable. Thread-local storage is a section of 
 * a thread's memory which is specific to it, and used for global variables, which, nevertheless, have to 
 * remain limited to that specific thread. (Me: Hence, a thread is assigned a particular memory locatio as
 * well inside the process. I didn't know that!)
 * 
 * This is very useful for a static variable like the one used here. That the generator instance is static 
 * is because we do not want to reinitialize it every single time we use this method, yet we do not want to 
 * share this instance across all threads. By using a thread-local, static instance, we can accomplish both 
 * goals. A static instance is created and used, but separately for each thread.
 * 
 * 


 * 
 */