/**
* When defining a templated member of a class outside the class, the template has to be redeclared.
*/
template <typename T>
struct my_struct {
	T f();
};


template<typename T>	// Template has to be redeclared.
T my_struct<T>::f(){}	// template has to be present in class definition.
