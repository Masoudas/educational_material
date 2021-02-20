/**
* Looking at a pointer, we know that it may or may not point to an object. But, we don't know who's responsible
* for managing it. A smart pointer then becomes the owner of the object, and is supposed to delete it.
* 
* There are three types smart pointers:
* -	unique_ptr: to represent exclusive ownership
* - shared_ptr: to represent shared ownership
* - weak_ptr: to break loops in circular shared data structures
*/