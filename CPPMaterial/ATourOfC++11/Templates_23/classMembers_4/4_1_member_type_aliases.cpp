/**
* using and typedef are supposed to make the design of the class simpler.
* The template argument name, T, is only accessible to the template itself, so for other code to refer
* to the element type, we must provide an alias (like we do for example when we implement iterators for containers).
*
* Type names as member aliases are often referred to as associated types. 
* If a class is missing a desired member alias, a trait can be used to compensate (discussed in chapter 28).
*/

template<typename T>
class Vector_iter {

};

template<typename T>
class Vector {
public:
	using type = T;
	using value_type = typename T::value_type;	// The template has its value type for example
	using iterator = Vector_iter<T>; // Vector_iter is defined elsewhere
	// ...
};
