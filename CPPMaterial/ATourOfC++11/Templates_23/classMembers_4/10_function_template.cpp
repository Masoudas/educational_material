/**
* As we've already observed, a compiler is capable to deduce the type of template, without having
* to actually indicate the template type. This shall be discussed more later.
* 
* Observer below how we ask for a comparator function as a template. Note that std::less is part of the 
* functional header.
*/
#include <functional>

using namespace std;

template <typename T>
void template_type_is_deduced(T t1, T t2) {
	template_type_is_deduced(int{}, int{});	// Type is deduced to be int
	template_type_is_deduced<int>(1, 2);	// Ok. type is specified as int.
}

template <typename T, typename COMP = less<T>>
void comparator(T t1, T t2) {
	COMP comp{};	// Never forget to instantiate the type!

	comp(t1, t2);
}