/**
* Before reading this, take a look at std::decay_t in chapter 35, type functions, and then std::invoke
* in chapter 33 (iterators), functional objects.
* 
* The thread class is used for creating a new thread of execution. The standard says:
* 
* "The class thread represents a single thread of execution. Threads allow multiple functions to execute 
* concurrently. 
* Threads begin execution immediately upon construction of the associated thread object (pending any OS 
* scheduling delays), starting at the top-level function provided as a constructor argument. The return value 
* of the top-level function is ignored and if it terminates by throwing an exception, std::terminate is 
* called. The top-level function may communicate its return value or an exception to the caller via 
* std::promise or by modifying shared variables (which may require synchronization, see std::mutex and 
* std::atomic.)
* 
* std::thread objects may also be in the state that does not represent any thread (after default construction, 
* move from, detach, or join), and a thread of execution may not be associated with any thread objects (after 
* detach).
* 
* No two std::thread objects may represent the same thread of execution; std::thread is not CopyConstructible 
* or CopyAssignable, although it is MoveConstructible and MoveAssignable."
* 
* The most important constructor of the thread class takes a function (pointer) and variadic templates as its
* argument:
* 
* template< class Function, class... Args >
* explicit thread( Function&& f, Args&&... args );
* 
* The standard says about this constructor: "Creates new std::thread object and associates it with a thread 
* of execution. The new thread of execution starts executing
* std::invoke(decay_copy(std::forward<Function>(f)), decay_copy(std::forward<Args>(args))...);"
* where the decay_copy functions is defined as:
* 
* template <class T>
* std::decay_t<T> decay_copy(T&& v) { return std::forward<T>(v); }
* 
* Except that the calls to decay_copy are evaluated in the context of the caller, so that any exceptions 
* thrown during evaluation and copying/moving of the arguments are thrown in the current thread, without 
* starting the new thread. The completion of the invocation of the constructor synchronizes-with 
* (as defined in std::memory_order) the beginning of the invocation of the copy of f on the new thread of 
* execution."
* 
* So two points are of interest here:
*	- The entire peparation of calling the new thread, including making the copy of passed function or args
*	  is done using the current thread. After that, the new thread is executed.
*	- To keep resources passed into the function, copies are made. For example, if an int variable n is 
*	  passed, a copy of it is made. If we want to pass by reference, we have to use std::ref.
*/