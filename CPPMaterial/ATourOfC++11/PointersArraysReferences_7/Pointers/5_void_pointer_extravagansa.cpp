/**
* First off, recall that we can't do any operation with void pointer, even taking the size.
* 
* Void pointer in C is a way to circumvent the type check, because in there we can say 
* void* = T*
* G* = void*
* 
* and the compiler does not throw a warning. However, the last assignment in C++ is not considered safe,
* and compiler throws an error. This is why we need an explicit cast there.
* 
* Question is, can we circumvent this by assigning const void* to const T*? Of course not, even though we 
* say const, we may still attempt to assign to the wrong type. So No!
*/

void assigning_const_void_ptr() {
	int x = 10;
	const void* p = &x;

	// const float* f = p;	// Not possible, and rightfully so!
}