/**
* Note that the mere definition of an array on stack is equivalent to initialization. That is, as soon as we
* write T* arr[n], we can read and write to the array. Albeit, the elements would be uninitialized. However,
* for custom types, there must be a default initalization (because memory layout for classes is important.)
* 
* Note also that a pointer has an initial (non-sense) value on the stack as well, which is why we should be 
* cautious not to dereference an uninitialized pointer, and in fact always assign to pointers as soon as we
* define them.
*/

struct S{ S(int ){} };

void array_acquisition_is_initialization() {
	//S s[2];	Error! No default constructors for S.
	S s[2] = { {2}, {2} };	// Fine!

	int x[5];		// Initialized to nonsense.
	int y[10] = {};	// Initialized to 0.
}