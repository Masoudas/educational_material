/**
* Tries to lock each of the given Lockable objects lock1, lock2, ..., lockn by calling try_lock in order beginning 
* with the first.
* 
* If a call to try_lock fails, no further call to try_lock is performed, unlock is called for any locked 
* objects and a 0-based index of the object that failed to lock is returned.
*
* If a call to try_lock results in an exception, unlock is called for any locked objects before rethrowing.
* 
* See C++ example????
*/