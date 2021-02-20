/**
* Destructor can be called virtual, and usually should be for a class with virtual method. This
* is to allow the destructor of the derived class to be called from the base class reference.
* We don't need to write override when writing destructor.
* 
* Note: We know that for a purely virtual this is definitely case. But what about a non-pure case?
* I suppose this should again be the case. Presence of word virtual implies that we may use the 
* base reference with derived class.
* 
* Note that in following, the destructor is called twice. Once, because we call it through the
* reference, the other time because d goes out of scope! That is why we it's called twice, not
* that by some magic destructor is called via the pointer.
*/
#include <iostream>
using namespace std;

struct virtual_distructor_base {
	virtual void f() = 0;
	virtual ~virtual_distructor_base() { cout << "Inside base destrcutor" << endl; };
};

struct derived : virtual_distructor_base{
	void f() override {}
	~derived(){ cout << "Inside derived destrcutor" << endl; }
};

void calling_derived_destructor_through_base_reference() {
	// virtual_distructor_base b = derived{};	Recall that this is impossible, because b can't allocated
								// memory, for having virtual method. Hence, copy constructor won't work!
	derived d{};
	virtual_distructor_base* b = &d;
	b->~virtual_distructor_base();
	
}

//int main() {
//	calling_derived_destructor_through_base_reference();
//}