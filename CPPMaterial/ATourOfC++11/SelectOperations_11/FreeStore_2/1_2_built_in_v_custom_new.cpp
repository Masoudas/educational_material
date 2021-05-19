/** This is all me:
* Notice that in the definition of the new operator for non-array types, we get a size_t as well. This would
* imply that only bytes of memory are allocated, not the layout of memory using this operator. Therefore:
* 
*	-	Built-in types: For built-in types, only allocating memory is enough, since there's no complication
*		involved with them, and they can be easily destroyed. Hence, what's actually passed to operator new
*		is something like operator new(sizeof(int)) for example, where the focus is on sizeof.
* 
*	-	Custom types: With custom types, a ctor has to be used, and at least MSVC throws an error. Although,
*		this is not necessary as we discuss below.
*		Ok, this one is a little odd. So long as no members of a class have a destructor
*		that actually need some proper clean up, we can just allocate memory, and do whatever we want
*		with memory directly. Then, calling the destructor just removes the class and that's it, and
*		the memory is properly managed. The only time things get rough is when there's a destructor that's
*		actually doing something important, like a delete for a string.
*		Point being, I understand why new needs a constructor to actually build the class layout. Imagine
*		there's a pointer somewhere in the class. That memory MUST be initialized, otherwise, destruction
*		will cause an error. But other than that, we're good to manage memory without having to call the
*		constructor or destructor. This is shown below, where I even can call a method, or delete, which
*		calls the destructor.
* 
* A very interesting note: the functions of a class are not actually on the memory address of the class.
* This is why by casting a pointer, I can just call them. This does make sense. A function should not
* be copied in memory per class of course. Hence, this is the reason why we essentially can play with
* the memory of a class, and in fact a class is essentially a memory map, with some tweaks!
*/

#include <memory>
#include <iostream>

struct parent {
	int x;
	int y;
//	std::string str{};

	void print_x() {
		std::cout << x;
	}

	~parent() {

	}

};

struct child : parent {
	int z;
};

void manaing_memory_without_ctor() {
	auto ptr = std::malloc(sizeof(child));

	auto c_ptr = static_cast<child*>(ptr);
	c_ptr->x = 10;
	c_ptr->print_x();

	// Possibly do some work with the pointer
	delete c_ptr;	// Ooops. Calling the ctor of an uninitialized class.
}

//int main() {
//	manaing_memory_without_ctor();
//}

