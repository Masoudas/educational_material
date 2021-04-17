/**
* The template<> prefix says that this is a specialization that can be specified without a template  
* parameter. The template arguments for which the specialization is to be used are specified in <> 
* brackets after the name. That is, the <void*> says that this definition is to be used as the 
* implementation of every type for which T is void*.
* 
* template<typename T>
* struct type{}
* 
* template<>	// This is not a templated type anymore, but we need to keep interface
* struct type<void*>{}	// Every instance initialized with void* uses this.
* 
* An specialization like type<void*> that itself contains no templates is called a complete specialization.
* That is, there is no template parameter to specify or deduce when we use the specialization.
* 
* Now, contrast this defintion to the following:
* 
* template<typename T>
* struct type{}
* 
* template<typename T>	
* struct type<T*>{}	
* 
* In this case, the specialization itself is templated. Consequently, we repeat the templated type. Now,
* here's the difficult part: the template (in name) in the above example is still T. However, this special
* case is instantiated if we pass pointers (like int*.) The point being implied here is that inside the 
* class, if we wrote for example 'T t', then this t is still an instance of T (an int for example). It is
* not T* (or int*). When writing the specialization, this is an obvious point. However, when using the class, the ambiguity
* is that the user writes type<int*>
*/
#include <iostream>
template<typename T>
struct t_ptr {};

template<typename T>	// T is instantiated with int* for example
struct t_ptr <T*> {
	t_ptr(T t) {	// We're passing an int*
		std::cout << "The content of the passed value is " << t;
	}
};

void instantiate_ptr_templated_struct() {
	int val{ 5 };
	t_ptr<int*> t{val};
}

//int main() {
//	instantiate_ptr_templated_struct();
//}