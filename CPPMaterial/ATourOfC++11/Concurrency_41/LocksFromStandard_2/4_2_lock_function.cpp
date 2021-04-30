/**
* There's a function called std::lock that can be used to lock a mutex. The standard says:
* 

template< class Lockable1, class Lockable2, class... LockableN >
void lock( Lockable1& lock1, Lockable2& lock2, LockableN&... lockn );

* The objects are locked by an unspecified series of calls to lock, try_lock, and unlock. If a call to lock 
* or unlock results in an exception, unlock is called for any locked objects before rethrowing.
* 
* See C++ example!!!
*/