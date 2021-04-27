/** 
* Going back to what the big guy says "We can place objects anywhere by providing an allocator function with 
* extra arguments and then supplying such extra arguments when using new."
* 
* The big guy reminds us that "Note that every operator new() takes a size as its first argument and that the 
* size of the object allocated is implicitly supplied (me: from the type we supply to it). The operator new() 
* used by the new operator is chosen by the usual argument matching rules; every operator new() has a size_t 
* as its first argument."
* The "placement" operator new() is the simplest such allocator. It is defined in the standard header <new>:

void* operator new (size_t sz, void* p) noexcept; // place object of size sz at p
void* operator new[](size_t sz, void* p) noexcept; // place object of size sz at p
void operator delete (void* p, void*) noexcept; // if (p) make *p invalid
void operator delete[](void* p, void*) noexcept; // if (p) make *p invalid

*/

// void* operator new(size_t, void* p) { return p; } // explicit placement operator. This is a standard
// operator, and the syntax is given as a reminder. It's in the new header
#include <new>

void allocation_by_specifying_address_explicitly() {
	struct X {};

	void* buf = reinterpret_cast<void*>(0xF00F); // significant address
	X* p2 = new(buf) X; // construct an X at buf;	Placement syntax notion of new operator
	// invokes: operator new(sizeof(X),buf)
}