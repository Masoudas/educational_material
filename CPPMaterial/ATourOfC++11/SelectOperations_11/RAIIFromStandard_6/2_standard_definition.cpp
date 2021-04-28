/**
* According to the standard:
* 
* Resource Acquisition Is Initialization or RAII, is a C++ programming technique which binds the life cycle of 
* a resource that must be acquired before use (allocated heap memory, thread of execution, open socket, open 
* file, locked mutex, disk space, database connection—anything that exists in limited supply) to the lifetime 
* of an object. 
*
* RAII guarantees that the resource is available to any function that may access the object (resource 
* availability is a class invariant, eliminating redundant runtime tests). It also guarantees that all 
* resources are released when the lifetime of their controlling object ends, in reverse order of acquisition. 
* Likewise, if resource acquisition fails (the constructor exits with an exception), all resources acquired 
* by every fully-constructed member and base subobject are released in reverse order of initialization. This 
* leverages the core language features (object lifetime, scope exit, order of initialization and stack 
* unwinding) to eliminate resource leaks and guarantee exception safety. Another name for this technique is 
* Scope-Bound Resource Management (SBRM), after the basic use case where the lifetime of an RAII object ends 
* due to scope exit.
* 
* RAII can be summarized as follows:
*	-	encapsulate each resource into a class, where
*		-	the constructor acquires the resource and establishes all class invariants or throws an exception 
*			if that cannot be done,
*		-	the destructor releases the resource and never throws exceptions;
*	-	always use the resource via an instance of a RAII-class that either:
*		-	has automatic storage duration or temporary lifetime itself, or
*		-	has lifetime that is bounded by the lifetime of an automatic or temporary object
*	
* Move semantics make it possible to safely transfer resource ownership between objects, across scopes, and 
* in and out of threads, while maintaining resource safety.
* 
* Classes with open()/close(), lock()/unlock(), or init()/copyFrom()/destroy() member functions are typical 
* examples of non-RAII classes.
* 
* The example below shows how using a mutex with without a lock_guard may cause an eternal lock, which is
* avoided by RAII principles using a lock_guard wrapper (see 41, Lock guards.)
*/

#include <mutex>

std::mutex m;

bool everything_ok() {
    return false;
}

void bad() 
{
    m.lock();                    // acquire the mutex
 //   f();                         // if f() throws an exception, the mutex is never released
    if(!everything_ok()) return; // early return, the mutex is never released
    m.unlock();                  // if bad() reaches this statement, the mutex is released
}
 
void good()
{
    std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
//    f();                             // if f() throws an exception, the mutex is released
    if(!everything_ok()) return;       // early return, the mutex is released
}    