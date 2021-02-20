/**
* Say we have a pointer in an object that needs to be copied. We can use a shared_pointer to ensure that delocation
* of memory in entangled objects does not cause exception. Otherwise deleting one pointer causes the copy
* to throw an exception when accessing that shared memory. 
* 
* Note that this not take care of the shared memory between the two object (entanglement). It just ensures that
* deleting one pointer does not remove the memory completely.
* 
* Entangled objects lead to code that is very hard to manage without some form of garbage collection (e.g., shared_ptrs)
* 
* However, a shared_ptr is still a pointer, so we cannot consider objects containing a shared_ptr in
* isolation. Who can update the pointed-to object? How? When? If we are running in a multithreaded system, 
* is synchronization needed for access to the shared data? How can we be sure?
* Entangled objects (here, resulting from a shallow copy) is a source of complexity and errors that is
* at best partially solved by garbage collection (in any form)
*/
#include <iostream>

struct problematic {
	int* p; // a pointer
};

void working_with_problematic_object()
{
	problematic x{ int {0} };
	problematic y{ x }; // ‘‘copy’’ x
	*y.p = 1; // change y; affects x
	*x.p = 2; // change x; affects y
	delete y.p; // affects x and y
	y.p = new int{ 3 }; // OK: change y; does not affect x
	*x.p = 4; // oops: write to deallocated memory
}

struct non_problematic {
	std::shared_ptr<int> p;
};

void working_with_non_problematic_object()
{
	non_problematic x{};
	non_problematic y{ x }; // ‘‘copy’’ x
	*y.p = 1; // change y, affects x
	*x.p = 2; // change x; affects y
	y.p.reset(new int{ 3 }); // change y; affects x
	*x.p = 4; // change x; affects y
	
	// No deletion is allowed, hence the object does not go out of scope.
}