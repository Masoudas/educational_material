/**
 * (This is not complete!).
 * 
 * (Me: When we say resource acquisition is initialization, we mean that if the resource is acquired successfully,
 * it has been allocated in the memory, without throwing any exception.)
 * 
 * RAII guarantees that a resource is available to another object that needs it. It also throws
 * an exception if the resource cannot be acquired. Finally, it destroys any resource acquired
 * by the class hierarchy from bottom to top, WITHOUT throwing any exceptions,
 * 
 * RAII is possible either using shared pointers, weak pointers, or unique pointers. Using
 * move semantics is another way of ensuring that.
 */