/**
* As we already know, an integer template argument must be a constant (Me: I don't understand the insistence on 
* it being an integer!)
* 
* Conversely, we can't assign to a template.  A value template parameter is a constant within the template so that 
* an attempt to change the value of a parameter is an error. (Me: Indeed, the error thrown by the compiler is that 
* the template is not an lvalue, which is easier to recall than it being constant.)
*/

template<double l, int N>
void function_accepting_double_and_int_temp() {
}


void using_double_int_templated() {
	function_accepting_double_and_int_temp<5.0, 2>();

}