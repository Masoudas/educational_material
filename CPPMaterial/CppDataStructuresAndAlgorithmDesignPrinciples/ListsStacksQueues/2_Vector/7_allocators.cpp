/**
* As opposed to arrays, vectors allow us to provide an allocator for memory management. The allocator
* provides the following functionalities:
* 1- Allocation of memory: Allocate memory in a particular location of memory.
* 2- Dellocation of memory: Release the allocated memory.
* 3- Construction: Construct the object(s) of the type
* 4- Destruction: Destroy the created objects in the memory.
* 
* As of CPP20, allocator_traits should be used rather than allocator directly, at least in MSVC, 
* given that many methods of the latter are deprecated.
* 
* Now we can see how allocators are used in emplace functions. Especially, how they avoid extra header
* of object construction and assignment by allocating memory and constructing object.
* 
* Question: How do we supply a custom allocator for vector? Does it suffice to just give the template
* (and the class makes one), or we have to supply an instance? We have to supply an actual instance of the
* allocator through various constructors.
*/

#include <memory>
#include <iostream>

using namespace std;

struct W {
	W() { cout << "Creating the new object\n"; }
	W(int, int) { cout << "Creating the new object\n"; }

};

using std::allocator_traits;

void std_allocator() {
	std::allocator<W> old_allocer{};
	allocator_traits<std::allocator<W>> allocer{};

	cout << "Allocating the memory location ...\n";
	W* ptr = allocer.allocate(old_allocer, 3U);	// Allocate three memory chuncks of the type W and get the pointer
	cout << "Note that no object construction took place as opposed to new \n";

	allocer.construct(old_allocer, ptr, 1, 1);	// Now, construct each memory location!
	allocer.construct(old_allocer, ptr + 1, 1, 1);	// Now, construct each memory location!
	allocer.construct(old_allocer, ptr + 2, 1, 1);	// Now, construct each memory location!

	allocer.destroy(old_allocer, ptr); allocer.destroy(old_allocer, ptr + 1); 
	allocer.destroy(old_allocer, ptr + 2);

	allocer.deallocate(old_allocer, ptr, 3);

	cout << "Now compare this to new ...\n";
	W* ptr1 = new W[3];	// This one uses the default constructor. If there weren't any, it would throw an exception.
	cout << "Three objects were constructed at once ...\n";

}

//int main() {
//	std_allocator();
//}