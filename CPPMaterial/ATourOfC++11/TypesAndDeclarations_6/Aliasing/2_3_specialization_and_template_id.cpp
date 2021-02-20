/**
* Consider the following alias template. When the result of specializing an alias template is a dependent template-id, 
* subsequent substitutions apply to that template-id:
*/

template<typename...>
using void_t = int;	

template<typename T>
void_t<typename T::foo> void_t_returner();
// f<int>(); // error, int does not have a nested type foo

template <typename T>
void_t<T> void_int_retuner(){
	return 5;
}

