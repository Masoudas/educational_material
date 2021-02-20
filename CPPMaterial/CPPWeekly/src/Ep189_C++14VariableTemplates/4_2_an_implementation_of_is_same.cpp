/**
* So now that we understand specialization, take a look at the following example, where we try to 
* implement is same as a template variable specialization. Notice that two types are always assumed
* not to be the same. The special case occurs when they're the same, in which case, we return true.
* But for that, we need to say is_same<T,T> = true. But for that, we need to declare T as a single 
* template, therefore we say the following:
*/
#include <iostream>

template<typename T, typename U>
constexpr auto is_same = false;

template<typename T>
constexpr auto is_same<T, T> = true;

struct X{};
struct Y : X{};

void using_is_same() {
	if constexpr (is_same<int, int>) {
		std::cout << "int and int are the same types\n";
	}

	if constexpr (!is_same<X, Y>) {
		std::cout << "X and Y are not the same types\n";
	}
}

//int main() {
//	using_is_same();
//}