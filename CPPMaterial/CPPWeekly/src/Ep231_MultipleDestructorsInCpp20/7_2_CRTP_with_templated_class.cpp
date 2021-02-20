/*
* As we can see, CRTP can be applied even when the derived class is templated itself.
* 
* But notice that in this case, if we want to do something with the template parameter, we need to
* have access to it, hence decalaring the type.
*/
#include <iostream>


template<typename T>
struct Comparable_t {
	~Comparable_t() {
		using type = typename T::Type;
		type s1 = static_cast<T*>(this)->s;
	}
};

struct S {
	S() { std::cout << "Constructed"; }
};

template<typename T>
struct S1_t : Comparable_t<S1_t<T>> {
	using Type = T;
	S s{};
};

void creating_s1_instance() {
	S1_t<S> s{};
	Comparable_t<S1_t<S>>& b = s;	// Christ!
}

//int main() {
//	creating_s1_instance();
//}