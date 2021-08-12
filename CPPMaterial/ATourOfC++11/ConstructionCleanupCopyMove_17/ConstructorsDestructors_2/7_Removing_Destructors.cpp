/**
* It's also possible to remove destructors. We can either delete them, or we can declare them private.
* Calling a destructor private is more flexible, because we'd have the opportunity to call it elsewhere
* inside our class.
*
* Me: Recall that in delete, destruction of an object does not imply releasing the memory, but the
* converse is true. That is, calling the destructor implies deleting the memory.
* 
* If the destructor is called, then the object is destroyed. So what happens when it goes out of scope
* for example? If an object is auto or static, then when trying to call the destructor, an exception
* is raised. So the compiler won't let us do it. With heap objects however, we have to call the
* destructor in any case. Hence, for such objects, it's fine to have private destructors. In fact
* this is a way to ensure that an object is always created in heap.
* 
* Note: We see finally the point mentioned in 3_Destruction. If we call destructor as private, the default
* constructor disappears.
*
* Note: As we see below, the heap created object can't be deleted. Because after all, there's no destructor.
* To free it, however, we need to use c-style coding, using the 'free' method. Use valgrind to check it!
*/
#include <iostream>
using namespace std;

class private_destructor {
private:
	~private_destructor() { cout << "calling the destructor" << endl; }

public:
	// private_destructor() = default;  Why wouldn't this work? And has to be explicitly written!
	private_destructor() {};
	private_destructor(private_destructor&) = default;
	private_destructor(private_destructor&&) = default;
	private_destructor& operator=(private_destructor&) = default;
	private_destructor& operator=(private_destructor&&) = default;
	
	void calling_destructor() {
		this->~private_destructor();
	}
};


void leakage_due_to_private_destructor() {
	//private_destructor p1{}; This is not allowed.

	private_destructor* p2 = new private_destructor{};
	p2->calling_destructor();

	//delete p2; Impossible! There's no destructor.
	//free(p2); //Removing the memory.
}
