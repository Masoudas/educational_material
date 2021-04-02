/**
* As we already know, when a class template has an alias with 'using', if that alias is to be used outside the class, it
* must be preceded by template. This is famous specially for type functions (see chapter 28.) For example:
* 
* typename remove_reference<T>::type.
* 
* Note that at the same time, with a particular type, we needn't write typename:
* remove_reference<int&>::type.
* 
* Also, note that for non-templated types, we again, don't use typename. For example, if class S has an alias, we simply
* have to write:
* S::type s;
* 
* Another case that I've come across is this. Consider and enum "enum class e : char {e, e1}" Now, if we wanted to know
* the underlying type, we'd need to use std::underlying_type as follows (this is what the big guy does in page 781):
* typename std::underlying_type<e>::type x = 10;
* 
* This last one however seem to be unnecessary, and I checked as far back as C++14, and the program compiles. The 
* standard says "A name used in a template declaration or definition and that is dependent on a template-parameter is 
* assumed not to name a type unless the applicable name lookup finds a type name or the name is qualified by the keyword 
* typename."
* 
* In conclusion, if we're using a template and then using type, then we need to include typename before it to indicate to
* the compiler that a type is being declared. Otherwise, there's no need for this.
* 
*/

#include <type_traits>

template<typename T>
typename std::decay<T>::type decay_type() {
	return {};
}

std::decay<int&>::type removes_int_ref() {
	return 5;
}

enum class e : char {e1, e2};

void create_underlying_type() {
	std::underlying_type<e>::type t = 10;
}

