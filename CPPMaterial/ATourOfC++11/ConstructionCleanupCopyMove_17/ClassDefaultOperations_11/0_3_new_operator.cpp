/**
* We can override the default new operation of the class as well, or even delete it. Note that the return
* pointer is a void pointer, rather than a pointer of the class type. 
* 
* The signature is both for array type and for single instance.
*/
#include <iostream>
using namespace std;

class my_class {
	void* operator new(size_t) = delete;

public:
	void operator delete(void* ptr) { cout << "inside delete operation"; };
};

void not_my_heap_class() {
	// my_class* ptr = new my_class{}; Not allowed
	my_class c1{};
	my_class* ptr = &c1;

	delete ptr;	
}

//int main() {
//	not_my_heap_class();
//}