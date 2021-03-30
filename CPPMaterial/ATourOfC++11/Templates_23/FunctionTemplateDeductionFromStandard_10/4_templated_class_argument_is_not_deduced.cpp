/** This is from me:
* The only templated type that is deduced in C++ is the initializer list. 
* 
* Suppose I've a class S<T>. The only way feasable for the template parameter to be deduced is to actually 
* write the template (because as we already know class template except for some cases from C++17 can't be deduced.)
* The only case that this is possible is as we already discussed for init lists.
* 
* The reason why this is important is because type_trait classes such as remove_refernce, remove_cv_qualifiers
* and etc are all themselves classes. Hence, if I try and pass on a parameter to a function that has those
* when defining argument type, the argument can't be deduced.
*/

#include <type_traits>

template<typename T>
struct S {
	S(int) {};
};

template<typename T>
void uses_templated_struct(S<T>) {
	uses_templated_struct(S<char>{1});
}

template<typename T>
void removes_reference(std::remove_reference_t<T>, int& x) {
	// removes_reference(x, x); Error! P can't be deduced, because class template is not specified for the class.
}