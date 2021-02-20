/**
* It's also possible to remove destructor. We can either delete it, or we can declare it private.
* Calling it private is more flexible, because we'd have the opportunity to call it elsewhere.
* 
* 
* If destructor is called, then the object is destroyed. So what happens when it goes out of scope
* for example? If object is auto or static, then when trying to call the destructor, an exception
* is raised. So the compiler won't let us do it. With heap objects however, we have to call the
* destructor in any case. Hence, for such objects, it's fine to have private destructors. In fact
* this is a way to ensure that an object is always created in heap.
* 
* Note: We see finally the point mentioned in 3_Destruction. If we call destructor as private, the default
* constructor disappears.
*/
#include <iostream>
using namespace std;

class private_destructor {
private:
	~private_destructor() { cout << "calling destructor" << endl; }

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
}