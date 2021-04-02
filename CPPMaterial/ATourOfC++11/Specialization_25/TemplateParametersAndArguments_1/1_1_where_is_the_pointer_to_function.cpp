
/**
* Why can we pass a function to template with writing the start?
* 
*/
???
template<typename T>
struct function {
	T t;

	function(T t){}

	T f() {
		return t;
	}
};

void my_f() {}

void initializing_function() {
	//function<void()> f1 = my_f;	// What is void?
	//f1.f();	// Error! Function can't return function.

	function<void(*)()> f2 = my_f;
	f2.f();	// Ok! function can return pointer to function.


}