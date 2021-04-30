/**
* The following two definitions are given by the standard:
* 
*	-	BasicLockable
* The BasicLockable requirements describe the minimal characteristics of types that provide exclusive 
* blocking semantics for execution agents (i.e. threads).
* For type L to be BasicLockable, the following conditions have to be satisfied for an object m of type L:
*	m.lock()	:	Blocks until a lock can be obtained for the current execution agent (thread, process, 
*					task). If an exception is thrown, no lock is obtained.
*	m.unlock()	:	The current execution agent should hold the lock m.	Releases the lock held by the 
*					execution agent. Throws no exceptions.
* 
*
*	-	Lockable
* The Lockable requirements extends the BasicLockable requirements to include attempted locking.
* For type L to be Lockable, it must meet the above condition as well as the following:
*	m.try_lock()	:	Attempts to acquire the lock for the current execution agent (thread, process, 
*						task) without blocking. If an exception is thrown, no lock is obtained.	true if 
*						the lock was acquired, false otherwise
*/ 