/** This is all me:
* When we pass an argument to a function, we can think of the argument as declarations, waiting to be
* filled. What does it mean? Imagine a function gets a string. Then we say f(string s). We can think
* of this as string s = What is passed to it. Hence because this is declaration, we use copy constructor
* Moreover, if has implicit constructor, we can use them. For example f("a") equivalent to 
* string s = "a".
* 
* Now, compare this to the case where f(const T&) or f(T&). In both cases, we're saying respectively:
* const T& = ... or T& = ...
*/
#include <string>
using namespace std;

void now_we_know_why_implicit_conversion_takes_place(string s) {
	now_we_know_why_implicit_conversion_takes_place("ss");
}

void even_with_rvalue_ref(string&& s) {
	// string s = Use move constructor of what is given outside.
	even_with_rvalue_ref("a"); // like saying string s = "a" again. Move constructor is used only if it can be used!
							   // Does not stop object from being constructed.
}
