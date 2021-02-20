/**
* In CPP, we can set compile-time conditions on what class wh inherit from!
* 
* As an example, below we say that if base class has default empty constructor, use it, otherwise use
* the other type (I don't want to go into using templates to make this example easy).
* 
* Note that the conditional_t is a template itself, hence we use <> to set it's value (It's the meta
* programming stuff).
*/
#include <type_traits>
using namespace std;

struct base_trv{};

struct base_non_trv {
	base_non_trv(int t){}
};

struct derived : conditional_t<is_trivially_constructible_v<base_trv>,
	base_trv,
	base_non_trv> {

};

void checking_derived_type() {
	derived d{};
	base_trv& v = d;	// Avoid slicing. LoL!

	// base_non_trv& v = d; Now, this does not work!
}