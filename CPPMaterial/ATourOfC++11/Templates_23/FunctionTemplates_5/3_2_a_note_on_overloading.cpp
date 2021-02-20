/** This is me:
* Say I have a templated function. Is it possible to overload a particular template? No. Because when
* calling the function, there would be ambiguity for the function to be chosen.
* 
* Note however that we can overload a function with or without template, in which case we have to
* indicate that we want the non-template version to be called by not giving template. And also, 
* note that we can delete a particular template too.
*/

void overloaded_function_with_temp(int x) {}

template<typename T>
void overloaded_function_with_temp(T x) {}

template<typename T>
void overloaded_function_with_temp(float x) = delete;


void using_overrides() {
	overloaded_function_with_temp(5);	// Fine. using int version
	overloaded_function_with_temp(5.2);	// Careful. Still calling the int function, due to implicit conversion.
	overloaded_function_with_temp<double>(5.2);	// Now calling the template function
	// overloaded_function_with_temp<float>(5.2f);	// Error! Deleted function.
}