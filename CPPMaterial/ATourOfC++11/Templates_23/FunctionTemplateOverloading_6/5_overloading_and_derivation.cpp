/**
* The overload resolution rules ensure that function templates interact properly with inheritance.
* 
* In this example, the function template f() accepts a B<T>* for any type T. We hav e an argument of type D<int>*, 
* so the compiler easily deduces that by choosing T to be int, the call can be uniquely resolved to a call of 
* f(B<int>*)
*/

template<typename T>
class B { };

template<typename T>
class D : public B<T> { };

template<typename T> void function_getting_pointer_to_base_templated_type(B<T>*) {};

void using_base_and_derived_references(B<int>* pb, D<int>* pd)
{
	function_getting_pointer_to_base_templated_type(pb); // f<int>(pb) of course
	function_getting_pointer_to_base_templated_type(pd); // f<int>(static_cast<B<int>*>(pd));
	// standard conversion D<int>* to B<int>* used
}