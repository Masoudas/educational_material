/**
* Of course if I were to do this in C, I'd use malloc to allocate enough memory for all objects, and then
* place each element inside. The problem with this approach however is that I need to know to the objects
* before hand.
*/
#include <string>

void a_scheme_of_c_implementation() {
	int x = 10;
	double y = 20.2;

	void* ptr = malloc(sizeof(int) + sizeof(double));

	int* int_ptr = static_cast<int*>(ptr);
	
	double* double_ptr = reinterpret_cast<double*>(int_ptr + 1); 

	// Now assign and do whatever!
}