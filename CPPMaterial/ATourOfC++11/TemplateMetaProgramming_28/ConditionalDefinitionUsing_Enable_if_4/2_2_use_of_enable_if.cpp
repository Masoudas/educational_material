/**
* The big guy says "I introduced the Enable_if as a default template argument because that is the most general solution. 
* It can be used for templates without arguments and/or without return types. However, in this case, we could alternatively 
* apply it to the constructor argument type."
* 
* 
*/
#include <type_traits>
#include <iterator>
#include <string>

template<typename T>
struct is_input_iter {	// There's no such class in the standard.
	static constexpr bool value = true;
};

template<typename T>
bool is_input_iter_v = is_input_iter<T>::value;

template<typename T>
class vector_implementation_two {
public:
	vector_implementation_two(size_t n, const T& val) {}; // n elements of type T with value val
	template<typename Iter>
	vector_implementation_two(std::enable_if_t<is_input_iter_v<Iter>, Iter> b, Iter e) {}; // initialize from [b:e)
	// ...
};

// Another self written example:
struct S {
	template<typename T, typename T1 = std::enable_if_t<std::is_class_v<T>, T>>		// Notice that T can't be used 
						// recursively, We can't say template<typename T = enable_if<, T>>, because T is undefined.
	S(T t) {
	}
};

void instantiation() {
	//S s{ 5 };
	S s{ std::string{""} };
}
