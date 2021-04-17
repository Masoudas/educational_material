/** This is still me:
* One approach the big guy uses in these true or false situations is to inherit from two traits called true_type
* and false_type. Is it a better approach? We follow what the big guy says. 
* 
* As the example below demonstrates, for our false specialization (or primary template) we inherit from 
* false_type, and for true, from true_type.
*/
#include <type_traits>

template<typename T>
struct ptr_predicate : std::false_type {};

template<typename T>
struct ptr_predicate<T*> : std::true_type{};

template<typename T>
bool ptr_predicate_t = ptr_predicate<T>::value;

void using_ptr_predicate() {
	auto int_is_not = ptr_predicate_t<int>;
	auto int_ptr_is = ptr_predicate_t<int*>;
}