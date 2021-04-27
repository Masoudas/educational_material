/**
* These are from the standard.
* 
* -	joinable: 
* Checks if the std::thread object identifies an active thread of execution. Specifically, returns true 
* if get_id() != std::thread::id(). So a default constructed thread is not joinable.
* A thread that has finished executing code, but has not yet been joined is still considered an active thread 
* of execution and is therefore joinable. 
* (Me: Hence, we can't check whether the thread is alive or dead using joinable. With joinable, we just want
* to check whether a thread has been joined or not. This is important, because if a thread has not been joined
* and the program terminates, std::terminate() is called and an exception is thrown.)
* 
* - join:
* Blocks the current thread until the thread identified by *this finishes its execution.
* The completion of the thread identified by *this synchronizes with the corresponding successful return 
* from join().
* No synchronization is performed on *this itself. Concurrently calling join() on the same thread object 
* from multiple threads constitutes a data race that results in undefined behavior. (Me: Jesus! Only one thread
* can join. I didn't know that!)
* Error Conditions:
* resource_deadlock_would_occur if this->get_id() == std::this_thread::get_id() (deadlock detected).
* no_such_process if the thread is not valid.
* invalid_argument if joinable() is false.
* (ME: The first one implies that we can't join ourself.)
* 
* -	detach:
* Separates the thread of execution from the thread object, allowing execution to continue independently. 
* Any allocated resources will be freed once the thread exits. After calling detach *this no longer owns any 
* thread.
* Postconditions: joinable is false.
* std::system_error if joinable() == false or an error occurs.
*/