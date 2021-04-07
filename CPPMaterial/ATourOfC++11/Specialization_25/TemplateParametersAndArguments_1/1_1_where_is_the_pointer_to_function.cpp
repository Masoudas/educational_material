/** This is me:
* Here's an observation: We can pass to templates the signature of a function. That is, suppose we define the function
* template as given below, we can define an instantiation as function<void()>. What is this?
* 
* On the other hand, recall that a function pointer is a type. Hence, we can pass that as a template too. In that case,
* what would be the difference between the two?
* 
* Note the difference between the two. Whereas with f, we're only allowed to use the function, with g, we need to assign
* a function to it to make it a pointer to an actuall location memory, in order to be able to execute it.
* 
* The big guy makes a reference to section 14.3 of the iso++11 and I checked it there. It's just the f and g example
* I've shown below.
* 
* I think this has something to do with the definition functor, or function objects (objects that can be called with ()), 
* but I'm not sure. A search for function objects in cpp reference definitely helps.
* 
* Note that we can't pass my_f to function, because my_f itself is the name of the function, not a type.
* 
*/

template<typename T>
struct function {
	using type = T;
};

void my_f() {}

void checking_type_of_template() {
	function<void(int, int)>::type f; // I can't assign to this expression.
	//f(5, 5);	// What now? What is being called here?

	function<void(*)()>::type g = my_f;
	g();
}

template<class T> void a_templated_method() {};
template<int I> void a_templated_method() {};

void template_method() {
	a_templated_method<int()>(); // int() is a type-id: call the first f()
}

void initializing_function() {
	//function<void()> f1 = my_f;	// What is void?
	//f1.f();	// Error! Function can't return function.

	//function<void(*)()> f2 = my_f;
	//f2.f();	// Ok! function can return pointer to function.


}
