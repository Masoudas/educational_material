/**
* Imagine the argument type (P) is not a reference (meaning the argument in function template does not say 'T& t' 
* for example.) The standard states that:
* 
*	(a) if A is an array type, A is replaced by the pointer type obtained from array-to-pointer conversion;
*	(b) otherwise, if A is a function type, A is replaced by the pointer type obtained from 
*		function-to-pointer conversion;
*	(c) otherwise, if A is a cv-qualified type, the top-level cv-qualifiers are ignored for deduction.
* 
* Why is the last rule important? Imagine we write a function templated as follows:
* template<typename T>
* void f(T t){t++;};
* 
* Now suppose a user that does not know the implementation of this function passes const int = 5 inside. Had
* the type been deduced as const int, it would have been a run-time error (trying to change const.) Hence,
* indeed this is a quite useful rule for us. Thank you Bjarne!
* 
* Note that (c) does not violate cv-qualification. In fact, we HAVE TO copy the value to pass it inside the 
* function. Hence, we're not changing a const value inside the function.
* 
* On the other hand, image P is a reference:
* 
* template<typename T>
* void f(T& t);
* 
* Now suppose I say:
* const int x = 10
* f(x);
* 
* In this case, const is not removed from A, because, x is now passed as reference, Therefore, I'd be able to
* manipulate x inside the function, diregarding the fact that it's a constant. Hence, const is removed from 'A' 
* ONLY if we're dealing with non references
* 
*/


template<class T> void templated_func(T t) { t++; };

void using_templated_func() {
	//int a[3];
	//templated_func(a); // P = T, A = int[3], adjusted to int*: deduced T = int*

	//void b(int);
	//templated_func(b); // P = T, A = void(int), adjusted to void(*)(int): deduced T = void(*)(int)
	
	const int c = 13;
	templated_func(c); // P = T, A = const int, adjusted to int: deduced T = int

	templated_func("aaa");	// This one however is A = const char*!!!
}
