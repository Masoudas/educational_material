/**
* There's something that I've been paying attention to, but not as much as I hoped to.
* 
* When we pass functions (particularly closures), especially as template parameters, the parameter is copied.
* Therefore, it's best to pass it as we do any parameter, as constant reference, or as rvalue reference. In 
* particular, suppose we receive a template reference, and we want to pass it to another function. We do so
* using the forward function. Although oddly enough, it seems that moving the template does not invalidate
* the original lambda. So in fact, it does appear that the move version creates two copies of lambda. Therefore,
* it's better to use the const ref version. * 
* Now, as I just remembered, one reason we give rvalue is to allow to pass function name, like passing std::functional
* functions. See below for an example of passing a function as rvalue.
* 
* Do we need to do the same with function pointers? No, because function pointers are just pointers to memory
* location, so we don't need to pass them by anything other than the pointer itself.
*/
#include <utility>
#include <iostream>
#include <functional>

template<typename T>
bool compare(const int left, const int right, T&& f) {	// 
	T closure = std::move(f);	// For some unGodly reason we first move.
	std::cout << "The moved lambada is at address: " << &closure << '\n';
	return closure(left, right);
}

template<typename T>
bool compare(const int left, const T& f) {	// 
	std::cout << "The const ref lambada is at address: " << &f << '\n';
	return f(left, left);
}

bool my_int_compare(int, int) { return false; }

bool compare_user() {
	auto comparator = [](int, int)->bool { return false; };
	std::cout << "The original lambada is at address: " << &comparator << '\n';
	
	compare({}, comparator);
	compare({}, {}, std::move(comparator)); // Nonsense. Not like this!
	compare({}, {}, my_int_compare);	// This one is passed as rvalue!!!


	return comparator(5, 5);	// The lambda is not invalidated after move.
}

void function_for_fptr() {
	using fptr = void (*)();

	fptr ptr1 = function_for_fptr;
	fptr ptr2 = &function_for_fptr;	// A function pointer is just a pointer. No need to pass it as a const reference
									// or anything else.
}


//int main() {
//	return !compare_user();
//}


