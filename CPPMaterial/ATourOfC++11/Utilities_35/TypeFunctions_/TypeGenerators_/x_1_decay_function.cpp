/**
* It's obviously used to decay radioactive std::atomic types into non-radioactive ones!
* 
* Me: The decay struct is particularly important when it comes to generating threads, and copying the resources
* of a thread. Essentially, decay is supposed to give back to us the purest type possible, a type purifier. 
* Hence, if we gave it a type qualified with cv or has reference, removes them. If we give it an array of a
* type, returns a pointer to an element (just like the normal definition of array decay). If we gave it a 
* function definition, returns a pointer to that function. The decay with arrays that we talk about is one 
* with static arrays, not pointers, or pointer to pointers. Such pointers are considered pure.
* 
* As is stated in the standard:
* 
* "Applies lvalue-to-rvalue, array-to-pointer, and function-to-pointer implicit conversions to the type T, 
* removes cv-qualifiers, and defines the resulting type as the member typedef type. More formally:
*	-	If T names the type "array of U" or "reference to array of U", the 'member typedef type' is U*
*	-	Otherwise, if T is a function type F or a reference thereto, the member typedef type is 
*		std::add_pointer<F>::type
*	-	Otherwise, the member typedef type is std::remove_cv<std::remove_reference<T>::type>::type.
* 
* Me:
* Naturally, we would want to use this structure with templates. Below, we give some of the basic examples.
* Note that this structure is defined in the type_trait header.
* Note also that it never says pointers are removed. Hence, a type with a pointer does not decay with this
* function.
*/
#include <type_traits>
void decay_types(int, int) {
	std::decay<int>::type x = 10;	// x is an integer.
	//std::decay_t<int>  x = 10;	// Equivalent.

	std::decay<int*>::type ptr = &x;	// int*. No decay.

	std::decay_t<int[10]> ptr_static = ptr;	// Decay to a pointer to integer as promised.

	std::decay_t<int&> no_ref = 10;	// Removing reference.

	std::decay_t<const volatile int> no_cv = 10;	// Removing cv qualifiers

	std::decay_t<int&&> no_r_value = x;	// Removes r-value.

	std::decay_t<void(int,int)> f_ptr = decay_types;	// Go figure what this is useful for!
														// Although, could save us from defining a decltype.
}

template<typename T>
void method_with_template(T&& x) {	
	std::decay_t<T> v = x;	// A copy of the templated type is guaranteed for v.
}