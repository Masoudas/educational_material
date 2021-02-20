/** This is not complete, and should be checked further.
* Note that auto takes place of type, and not cv qualifiers, or references for that matter. When we assign
* the return value of a function with auto for example, we're creating a new variable, and we just leave the
* type to be deduced by the compiler.
* 
* As it happens, auto does not detect cv qualifiers. This does make sense, as the compiler leaves it to us to
* determine whether the newly defined variable is const, volatile, etc.
* 
* Of course interesting exceptions can happen, mostly with references. For example, if we take a reference to
* the elements of an initializer list, they'd be const ref. This is because we're not supposed to write to an
* initializer list. Same thing happens to a pointer to constant for example (but not a const pointer, because
* we can always copy from a const to a non-const value).
*/
#include <initializer_list>

struct S {
	const int f() const {
		return 5;
	}
};

const int returns_const_int() {
	const int x = 10;
	auto l = returns_const_int(); // Not const! Caution!
	auto w = x;	// Not const, caution!

	S s{};
	auto r = s.f();	// Again, no CV is deduced!

	auto&& list = { S{}, S{}, S{}, S{} };
	auto val = *list.begin();


	int const* p = &x;
	auto p1 = p;	// Deduced as int const*

	int* const p2 = new int{ 2 };
	auto p3 = p2;	// Deduced as int*, and not int* const.

	return 5;
}