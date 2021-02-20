/**
* The unique_ptr (defined in <memory>) provides a semantics of strict ownership:
* - A unique_ptr owns the object to which it holds a pointer. That is, it is the unique_ptr’s obligation to destroy 
* the object pointed to (if any) by its contained pointer (ME: And not a copy of it for example, which conflates 
* responsibility.)
* - A unique_ptr cannot be copied (has no copy constructor or copy assignment). However, it can be moved (hence
* a function, can return a unqiue pointer).
* - A unique_ptr stores a pointer and deletes the object pointed to (if any) using the associated deleter (if any) 
* when it is itself destroyed (such as when a thread of control leaves the unique_ptr’s scope.)
* 
* The uses of unique_ptr include:
*	- Providing exception safety for dynamically allocated memory
*	- Passing ownership of dynamically allocated memory to a function
*	- Returning dynamically allocated memory from a function
*	- Storing pointers in containers (me: Otherwise, we need a call to delete[]).
* 
* Note that we can supply a deleter with the template, and if needed, through constructor as well.
*/
#include <memory>

std::unique_ptr<int> create_object_with_unique_ptr() {
	std::unique_ptr<int> p = std::unique_ptr<int>{ new int{5} };

	// Now, do what ever you want here.

	return p;	// The move constructor is used here.
}

// Once passed to this function, the function is responsible for taking care of the pointer
void pass_unique_ptr_object(std::unique_ptr<int> ptr) {
	std::unique_ptr<int> p = std::unique_ptr<int>{ new int{5} };

	pass_unique_ptr_object(std::move(p));	// Should be moved directly, otherwise uses copy constructor.
}


