/** This is all me
* Note that as Microsoft docs point out "When delete is used to deallocate memory for a C++ class object, the
* object's destructor is called before the object's memory is deallocated (if the object has a destructor)."
* 
* In other words, calling the destructor does not dellocate memory. It just destructs the internal of the 
* object. Therefore, delete is an ESSENTIAL part of dellocating memory. In other words, delete is not just a
* wrapper for destructor (which it would have been had we not needed to call delete!) As we may recall, the
* same scenraio happens with memory allocators when we allocated memory. First, memory is located, THEN, that
* memory is filled with the construction of object.
* 
* A destructor is a nice unified way to clean up the internal memory of the class (like if it has a pointer)
* before the class itself is destroyed. Hence, a destructed object is a null state, waiting to be removed
* from memory, on that in C++ we have to delete it ourselves. Hence, the following paragraph:
* 
* That being said, note that delete itself calls the destructor. Hence, indeed, it's wrong to call the destructor
* before calling delete. There's however a tiny exception. If the class has a default destructor, we can call
* it as many times as we want, and even before delete. This would not throw an error! This is independent of
* the data fields of the class, if they don't have a custom destructor.
* 
* For example, to compare when this experiment does not work, add an string somewhere in the class or its
* nested class. When it's being destructed, it's destructor is called. Therefore, upon deletion or repeated
* calling of destructor, we get an error.
* 
*/
#include <iostream>
#include <string>

struct S {
	struct S1 {};
	int x{10};
	S1 s{};

};

void experimenting_with_destructor() {
	S* s_ptr = new S{};

	// Call destructor as much as you want. So long as there's nothing inside the class to actually
	// destructo
	s_ptr->~S();
	s_ptr->~S();
	s_ptr->~S();

	if (s_ptr) std::cout << "The pointer is still valid, and has not been invalidated\n";
	std::cout << "x is still 10, because int has no destructor " << s_ptr->x;
	delete s_ptr;	// Disaster! object has already been destructed.
}

//int main() {
//	experimenting_with_destructor();
//}