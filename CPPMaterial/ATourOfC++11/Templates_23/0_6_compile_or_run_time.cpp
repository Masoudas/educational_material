/** This is me:
* A question that may arise here is that as we already know, a template specilaization is not generated
* until actually utilised. Does template generation happen at run-time or at compile time?
* 
* The latest evidence suggest that that it does happen at COMPILE time. i.e, the compiler sees a particular
* use of the template, and generates the corresponding version. Why? because in the following example,
* before any run-time information is available, the compiler sees that int does not have any
* value_type scopes, and throws an error.
*/
#include <string>

template<typename T>
void templates_are_generated_at_compile_time() {
	using type = typename T::value_type;
}

//int main() {
//	templates_are_generated_at_compile_time<std::string>();
//	templates_are_generated_at_compile_time<int>(); // Error caught at compile time, before any execution!
														
//}