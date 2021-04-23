/**
* As a reminder, in this example I try to create a vector that holds a common type to the given arguments.
* This is the example I saw in the CPPDataStructuresAndAlgorithms book.
* 
* The point is to find a common type among the types, using a type function. Note also the fact that we 
* can't forward variadic templates. Instead, we need to explicitly cast them to the common type. Finally,
* notice that we unpack the cast after the argument, because static_cast can unpack one argument at a
* time.
* 
* Why can't we forward here? I've absolutely no idea why! It should have been possible.
*/
#include <type_traits>
#include <vector>
#include <iostream>

template<typename...Args>
auto common_vec(Args&&...arg) -> std::vector<std::common_type_t<Args...>> {
	using common_type = std::common_type_t<Args...>;
	return { static_cast<common_type&&>(arg)... };
}

void test() {
	auto vec = common_vec(5, 52ll, 12l, 133u);	// Returns a double vector
	std::cout << "[" << vec[0] << ", " << vec[1] << ", " << vec[2] << ", " << vec[3] << "]";
}

//int main() {
//	test();
//}