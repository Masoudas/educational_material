/* This is me:
* Are destructors called automatically when an array goes out of scope on each element?
* 
* An array is a block of memory, either on stack or in heap. When we initialize an array (even 
* without explicitly calling the constructor) an object of the type is initialized in the memory location.
* Hence, if the array is on stack, when it goes out of scope, each memory location has to be destroyed, which
* is why the destructor is called. (recall that T arr[] is like T arr1 = ..., T arr2 = ..., i.e, declaring
* several variables.)
* 
* On the other hand, if we're on the heap, calling delete[] is like calling delete for evey single element. Hence,
* every object is once again destroyed.
* 
* Note sometimes you think T* t = new T; arr[0] = *t  would mean an object from heap is allocated to memory. However,
* we're just calling THE ASSIGNMENT operator here, which means the content of t would be assigned to the location
* already initialized by arr. Hence, no new object is placed there, and in the end the destructor is called on that
* array for each element).
*/

#include <iostream>
using namespace std;

struct mystruct {
	~mystruct() { cout << "Calling destructor" << endl; };
};
void destructing_array_on_stack() {
	mystruct *s1 = new mystruct{};
	mystruct arr[2] = {};	// Two objects are initialized on stack.
	arr[0] = *s1;	// This is an assignment operator. The arr memory address is not bounded to s1!!!

	cout << "Now that arr is going out of scope, the destructor on each element is called (two in total)" << endl;
	cout << "Note that the heap object never goes out of scope" << endl;
}


void destructing_array_on_heap() {
	mystruct *arr = new mystruct[2]{};	// Two objects are initialized on stack.

	cout << "Deleting the dynamic array calls the destructor on every element: " << endl;
	delete[] arr;
}

//int main() {
//	destructing_array_on_stack();
//	destructing_array_on_heap();
//}

