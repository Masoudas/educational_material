/** This is me:
* As we already know, value type_trait functions return a value, which can be used at compile-time, as well as at run time.
* 
* So note that because these functions return values and not types, we need to define a value inside of them, say bool value.
* But the question is, how can we make them accessible at compile time? Naturlich, we use constexpr. However, this is not
* enough, because we need to make it static, so that it would not be dependent on the instantiation of the class. Otherwise,
* the variable would only be accessible through instances of the class (with the dot operator) and not with the scope operator
* (::).
* 
* Now, this was regarding defining the class. Now the question is, how do we alias it as _v, so that we use it's value
* directly? The answer is, note that we're aliasing a value here, not a type. Hence, we can't say using. Instead, we 
* should write 'type name = value_type_function<T>', which is what we do for the boolean below.
*/
#include <string>



template<typename T>
struct is_string {
	static constexpr bool value = false;	// The return value.
};

template<typename T>
struct is_string<std::basic_string<T>> {	// This is odd! Specializing with a templated type! Note that T is NOT
											// a string now, it's a char (set). See chapter 25, 0_3_Specialization with
											// a templated type.
	static constexpr bool value = true;	// The return value.
};

template<>
struct is_string<const char*>{
	static constexpr bool value = true;	// The return value.
};

template<typename T>
bool is_string_v = is_string<T>::value;	// Notice that the value is a bool. We don't say using because we're not
										// aliasing a type!

constexpr bool using_is_string_v() {
	return is_string_v<std::string> && is_string_v<const char*>;
}