/**
* One thing that always confuses is that when it comes to templated types, I always tend to forget that aliasing
* must be done WITH the templated type included. Hence for example I don't say:
*	
*	using vec = std::vector
* 
* but rather I say:
* 
*	using vec = std::vector<int>
* 
* Ok. So the way I should remember it is that in C++, we alias a full type. Hence for example I can alias a class
* that has no template, but if it has templates, I should alias it with templates included. This is an important
* notion (that we only alias types). This is why for example I can't alias a function.
* 
*/
#include <vector>
void a_function_cant_be_aliased() {
	// using f_alias = a_function_cant_be_aliased;
	using ptr = int*;	// A type can be aliased.
	using vec = std::vector<int>;
}