/**
* Apparently, one override of the plus sign works with function pointers as follows:
* T* operator+(T*);
* 
* As we can see, this is a unary operator. What does it do?
* 
* As we already know, lambdas are not function pointers, but rather closures. I think this is because captured
* lambdas cannot be considered function pointers (because how can we describe the capturing concept with a normal 
* function pointer. We can't!). 
* 
* Supposedly, we use it to cast from a captureless lambda to a function pointer! You can force the compiler to 
* generate lambda as a function pointer rather than closure by adding + in front of it.
* 
*/

void f1(int x){}

void using_plus_sign_overload_with_fptr() {
	auto func = f1;		// This would be a function pointer of type void(*)(int);
	
	using f_type = typename void(*)(int);	// Ok. Defining a new type.
	f_type func1 = [](int x) {x++; };	// Assigning a lambda to the function pointer. Works fine.
	func1 = [](int x) {x--;};	// Assiging a new lambda.

	auto func2 = [](){};	// Type is automatically deduced as a closure
	//auto func3 = +[](){};	// This is supposedly a function pointer, though it does not work!
	
}

