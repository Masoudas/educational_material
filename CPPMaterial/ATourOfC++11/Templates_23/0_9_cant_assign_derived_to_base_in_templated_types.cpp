/**
* As we may recall (and this was the case for example in Java), there's strong type checking when it comes to
* templates. This implies that a templated type with derived class can't be assigned to templated type of base.
* 
* This as because, as we said, a templated type is an ordinary type. Consequently in the example below, 
* templated<base> could be imagined as templated_base and templated<derived> as templated_derived. Hence, we can't
* assign to unrelated types to one another.
*/

struct base{};
struct derived : base {};

template<typename T>
struct templated {};

void cant_assign_templated_derive_to_base(){
	// templated<base>* ptr = new templated<derived>{}; Error! Assigning unrelated type.
}