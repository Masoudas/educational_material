/**
* Future me: Figure out why we can't specialize with either a templated type or a concrete templated types.
*/

#include <vector>

template <typename T>
void uses_templated_type_for_specialization() {

}

//template <typename T>
//void uses_templated_type_for_specialization<std::vector<T>>() { Error! Function template has already been defined.
//
//}

//template<>
//void uses_templated_type_for_specialization<std::vector<T>>() { // Illegal!
//
//}