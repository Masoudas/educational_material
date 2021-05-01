/**
* me: In essence, a scoped lock allows us to lock and unlock several locks together. Why is it called a scoped
* lock? No idea!
*
* The following is from the standard documentation:
* 
* The class scoped_lock is a mutex wrapper that provides a convenient RAII-style mechanism for owning one or 
* more mutexes for the duration of a scoped block. 
* 
* When a scoped_lock object is created, it attempts to take ownership of the mutexes it is given. When control 
* leaves the scope in which the scoped_lock object was created, the scoped_lock is destructed and the mutexes 
* are released, in reverse order. If several mutexes are given, deadlock avoidance algorithm is used as if by 
* std::lock.
* 
* The scoped_lock class is non-copyable
* 
*/