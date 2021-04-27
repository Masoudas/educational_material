/**
* Just like most ops in C++, new, delete, new[] and delete[] are all operators defined in the new header.
* Here's the definition of each operator. Notice the use of bracket for array operators is the only 
* difference between the two:

void* operator new(size_t);	// Allocate space for individual objects (size_t of memory)
void operator delete(void*)	// if (p) deallocate space allocated using operator new()

void* operator new[](size_t);	// new[]
void operator delete[](void*)	// delete[]

* Question: Is there an overload for built-in types? I checked, and the answer is no. Built-in types are
* handled separately I guess. Although, it's tempting to write a type function that would return the size,
* and then use that in conjunction with this raw new operator to define an object as an exercise. The 
* big guy says in this regard "The allocation and deallocation functions deal in untyped and uninitialized 
* memory (often called "raw memory"), as opposed to typed objects. Consequently, they take arguments or 
* return values of type void*. The operators new and delete handle the mapping between this untyped 
* memory layer and the typed-object layer." (me: Make of that what you will!)
* 
* As mentioned earlier, note that "The standard implementations of operator new() and operator new[]() do 
* not initialize the memory returned."
* 
* What happens when new can find no store to allocate? By default, the allocator throws a standard-library 
* bad_alloc exception (later, we shall discuss alternatives.) Please be careful: the new operator is not 
* guaranteed to throw when you run out of physical main memory. So, on a system with virtual memory, this 
* program can consume a lot of disk space and take a long time doing so before the exception is thrown.
* 
* We can specify what new should do upon memory exhaustion; see 30.4.1.3 of the book.
* 
* As we already know, we can overload the new operator for a user-defined types as a member operator.
* This shall be shown next. Class members operator new(), etc., are found and used in preference to the 
* ones from <new> according to the usual scope rules
* 
*/
#include <exception>

void throw_bad_alloc() {
	try {
		for (;;) {
			int* ptr = new int[10000];
		}
	}
	catch (std::bad_alloc& b) {

	}
}
