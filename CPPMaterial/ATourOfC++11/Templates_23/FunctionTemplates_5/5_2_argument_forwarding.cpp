/**
* Distinguishing between lvalue and rvalue references is particularly important for forwarding. In fact, if we note
* the definition of forwarding below, we see that:
* 
* 1- Because an rvalue (or a temp) is deduced as type T, then the second version is called, and it returns an rvalue
* reference.
* 2- For a variable name, the argument is deduced as T&, hence, the first version is called, and the return type 
* would be T&. This would save us from copying the passed variable unnecessarily (although allows change).
* 
* Question: Why doesn't forward work with a literal int or an int reference to give back an rvalue reference?
* 
* 
* In conclusion, forwarding should only be done with templates, and not types!
*/
#include <type_traits>

template<typename T>
T&& forwarding(typename std::remove_reference<T>::type& t) { return static_cast<T&&>(t); } // Why move here? Why not just 
																					// return t?

// Equivalently T&& forwarding(std::remove_reference_t<T>& t) { return std::move(t); }

template<typename T>
T&& forwarding(typename std::remove_reference<T>::type&& t) { return static_cast<T&&>(t); }
// Equivalently T&& forwarding(std::remove_reference_t<T>&& T) { return std::move(t); }

void using_forwarding_definition() {
	int i = 10;
	
	// int& j = forwarding(i); Does not work!
	// int&& j = forwarding(10); Does not work!

	
}

