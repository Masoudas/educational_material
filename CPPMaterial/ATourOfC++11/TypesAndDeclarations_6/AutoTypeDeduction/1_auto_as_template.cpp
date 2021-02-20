/**
* This seems a bit odd at first, but it shall become clear soon.
* 
* When defining templates, we can say 'template<auto n>' which implies type deduction in the template. Why on
* God's green Earth would we need this?
* 
* As we may recall, we can pass values as template as well, saying 'template <int N>'. Having such a deduction
* in the template would allow us to pass an arbitrary type.
* 
* One interesting example is given below, where we create a pair using auto deduction!
* 
*/
#include <utility>

template <auto n>
auto make_pair()->std::pair<decltype(n), decltype(n)> {
	return { n, n };
}

void creating_pair_from_make_pair() {
	auto pair = make_pair<0>();
}