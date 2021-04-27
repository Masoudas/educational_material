/**
* The C++ library classes that manage their own resources follow RAII: std::string, std::vector, std::jthread, 
* and many others acquire their resources in constructors (which throw exceptions on errors), release them in 
* their destructors (which never throw), and don't require explicit cleanup. 
* 
* In addition, the standard library offers several RAII wrappers to manage user-provided resources:
* std::unique_ptr and std::shared_ptr to manage dynamically-allocated memory or, with a user-provided deleter, 
* any resource represented by a plain pointer; std::lock_guard, std::unique_lock, std::shared_lock to manage 
* mutexes.
*/