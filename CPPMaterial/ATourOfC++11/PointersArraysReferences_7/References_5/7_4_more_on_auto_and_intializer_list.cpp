/**
* As we're already aware, use of brackets with auto creates an intializer_list type, assuming a common type
* can be deduced from all the elements of the list.
* 
* Same as any other temporary, we can define a temporary initializer list as well. Note however that when we
* do so, two things happen:
* 1- Because the iterator of initializer list is const, it's point less to move its content into an rvalue ref.
* We should rather use a const ref for that aim.
* 2- If used in a for range loop, again, we should use const ref over an lvalue ref. 
* 
* I still don't understand why initializer_list rvalues are cannot be perfect forwarded!
*/
#include <initializer_list>
#include <utility>

struct base {};
struct derived {};

void initializer_list_creation() {
	auto l = { 1, 2, 3, 4 };	// list type
	// auto n = { 1, 1.2 };	 // Error. Is it double or is it int?
	
	base b1, b2; derived d1, d2;
	auto l1 = { b1, b2 }; // Fine!
	// auto l = { b1, b2, d1, d2 }; Error! Can't detect type to be base!
}

void create_auto_ref_initializer_list() {
	auto&& l = { base{}, base{} };

	auto&& m = std::move(*l.begin());	// m is now a const rvalue ref, which is pointless
	auto& m1 = *l.begin();	// m1 is now a const ref, which is actually what we seek!
	auto&& m2 = *l.begin();	// As we know, this is the same as m2 too.
}