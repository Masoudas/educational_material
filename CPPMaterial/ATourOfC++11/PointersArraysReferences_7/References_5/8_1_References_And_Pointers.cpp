/*
* References and pointers have weaknesses and advantages. For example with pointers, we can increment and 
* decrement the memory location, but not with references, unless we get a pointer.
* 
* If you want to overload an object on a type, use references rather than pointers. This is because for example
* a normal addition operation does not accept pointers (we say 2 + 3, not int* + int*).
* 
* Note that as the following code shows, we can get the address of an object and assign it to a pointer, using a
* reference to that object.
* 
* Another point is that we can dereference a pointer and directly assign it to a reference. The compiler is 
* clever enough to figure this out, and keep the address of the pointer in the reference!
* 
*/
void increment_char_pointer(char* p) {
	while (*p) {
		// Do something;
		p++;
	}

}

void increment_char_ref(char& ref) {
	while(ref){
		// Do something
		ref++;	// Completely different meaning. Inifinite loop.
	}

	char* ptr = &ref;
	while (*ptr){}	// Now this makes sense.
}

class Matrix {
public:
	Matrix& operator+(const Matrix* ptr) { Matrix a{}; return a; }
	Matrix& operator+(const Matrix& ptr) { Matrix a{}; return a; }
};

void using_matrix_overloaded_addition() {
	Matrix m1{};

	m1 = m1 + m1;
	m1 = m1 + (&m1);	// Awkward I guess
}

void Ok_to_assing_pointer_value_to_reference_directly() {
	int x = 10;
	int* p = &x;

	int& ref = *p;

	ref = 20;	// x is now 20
}