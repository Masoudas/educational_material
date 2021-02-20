/**
* Note that an static member is not associated with any particular instance of the class, rather with all of them.
* Consequently, such a pointer needn't be used with a particular object, and can be used universally. Therefore,
* the big guy has decided that such a pointer is no different that an ordinary pointer
*/

struct static_mems {
	static int val;
	static void f() {};
};
int static_mems::val = 5;

void pointer_to_static_members_is_no_different_than_those_of_ordinary_pointers() {
	int* p = &static_mems::val;	// static member requires ordinary pointer
	void (*f_ptr)() = &static_mems::f;	// static method requires ordinary pointer to method!

	// void (static_mems::* f_ptr)() = &static_mems::f; Pointer to ordinary member assigned to pointer to function.
}