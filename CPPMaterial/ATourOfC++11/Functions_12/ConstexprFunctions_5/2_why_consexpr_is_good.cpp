/**
* Question is, why is it good or preferable to have constexpr objects rather than normal or even
* const objects?
* 
* Imagine a large object is created at compile time. Then when the application is functioning, it 
* does not have to wait for that object to be created. It's already been generated at compile time.
* Like for example, an image analyzer class has been created at compile time, hence it doesn't need
* to be generated at run-time, so we can go straight to analysis rather than wait for analyzer to
* be set up.
*/