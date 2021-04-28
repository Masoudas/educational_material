/** This is all me:
* As a reminder of how to overload the new and new[] operators for a custom type, we're going to implement
* one in the following example. Recall that always the first parameter is size_t.
* 
* Here's the question: How does one use the overloaded new operator? Because a type MUST ALWAYS be supplied
* to, the part new S is the same. However, any additional parameters thay we may add in our overloads (such
* as int* in the following example) must be supplied like a normal argument of an operator to the new. Hence,
* we see the use "new(Args) Type" pattern, as shown below.
* 
* The big guy says "Because of this usage, the new(buf) X syntax for supplying extra arguments to operator 
* new() is known as the placement syntax."
* 
* Note that the return type of the overloaded operator cannot change, and it has to be void* (no covariance
* between void* and S*)
*/
#include <iostream>

template<typename Alloc>
struct S {
	int t;

	void* operator new(size_t t) {
		void* ptr = Alloc.allocate(t);
		std::memcpy(ptr, new int, sizeof(int));	// Whatever!
		return ptr;
	}

	// More overloads
	void* operator new(size_t, int* p) {
		return (S*)(p);	// Just a simple cast!
	}

	void operator delete(void* p) {
		delete p;
	}

	void* operator new[](size_t) = delete;	// Can't make arrays of this object
	void operator delete[](void*) = delete;
};

void using_overloaded_p_version_two() {
	S<int>* s = new(new int) S<int>;	// Nice!
}
