/**
* Note that we can determine whether a type has a default (trivial) destructor using the is_trivially_destructible_v
* (variable, method?) in the type_traits header.
* 
*/
#include <type_traits>
#include <string>
#include <iostream>

struct S{};
struct S1 {
	~S1() {};
};

void check_if_type_is_trivially_destructible() {
	static_assert(std::is_trivially_destructible_v<S>, "");
	static_assert(!std::is_trivially_destructible_v<S1>, "");	// Not trivially destructible

	static_assert(std::is_trivially_destructible_v<int>, "");
	static_assert(!std::is_trivially_destructible_v<std::string>, "");

	if (std::is_trivially_destructible_v<int>) {
		std::cout << "Trivially destructible";
	}
}

//
//int main() {
//	check_if_type_is_trivially_destructible();
//}