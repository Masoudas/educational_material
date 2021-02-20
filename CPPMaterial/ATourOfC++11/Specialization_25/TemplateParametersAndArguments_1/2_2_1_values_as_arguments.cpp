/**
* A template parameter that is not a type or a template is called a value parameter and an argument passed to it a 
* value argument. For example, integer arguments come in handy for supplying sizes and limits. (Me: read 1, and once
* again recall that only built-in types can be passed as values.)
* 
* An argument for a template value parameter can be (§iso.14.3.2):
*	- An integral constant expression (me: int, long, etc)
*	- A pointer or a reference to an object or a function with external linkage (me: what now?)
*	- A non-overloaded pointer to member (me: what now?)
*	- A null pointer
* 
* A pointer used as a template argument must be of the form &of, where of is the name of an object or a function, 
* or of the form f, where f is the name of a function.	A pointer to member must be of the form &X::of, where of 
* is the name of a member. In particular, a string literal is not acceptable as a template argument.
* 
* (Me: Of course because templates are compile-time entitites, if we pass pointers, we need to ensure that they're
* all compile time entitites, which in turn implies that the entities they point to must be constexpr themselves, 
* which in turn brings about the whole discussion we had about literal types, which I still struggle with! Why
* would anyone want ot pass pointer to objects as templates? It allows for not passing the actual value (perhaps
* copying it) while passing it as template argument.)
* 
* This restriction, like the one against floating-point template value arguments, exists to simplify implementation 
* of separately compiled translation units. It is best to think of template value arguments as a mechanism for 
* passing integers and pointers to functions. Resist the temptation to try something more clever. Unfortunately 
* (for no fundamental reason), literal types cannot be used as template value parameters. The value template 
* arguments are the mechanism for some more advanced compile-time computation techniques.
* 
* (Me: A thought that comes to mind is that why didn't they ask for a pointer to function as template when writing
* algorithms such as sort for comparing the elements? For two reasons I think:
* - They wanted to allow passing lambdas
* - The function pointers would have needed templates, something like:
* template<typename T> bool compare(const T& lhs, const T& rhs){ ... }
* and then defined a signature for such method, which si probably too compliaced!
* 
*/
#include <iostream>

template<typename T, int max>
class Buffer {
	T v[max];	// Recall that an array must have compile-time size. Use pointers and new for dynamic arrays.
public:
	Buffer() { }
	// ...
};

struct S {
	void f() { std::cout << "inside member function passed by pointer as template \n"; };
};

using ptr_member = void (S::*)();
using ptr_f = void (*)(int);

// As we can see, we can pass all sorts of pointers as template arguments. Note that cv qualifiers are not allowd.
// Note that for the char* thing, we can't pass C-style string (for one thing, they're const!)
// Finally, note that even a custom type is passed a pointer
template<int* Int, char* Char, ptr_member Ptr_M, ptr_f Ptr_F >
void various_value_type_templates(S s) {
	// static_assert(Int != nullptr, "Passed pointer can't be null");
	(s.*Ptr_M)();
}

// Some constexpr types
constexpr int* i_ptr = nullptr;
char c_ptr[] = {'a', 'b', 'd', 'e'};	// Why on earth can I pass this one without it being constexpr?
										// This is because the size of this array is static, and template can
										// take care of it.
constexpr S s; 

void void_returner_int_passer(int){}

void instantiation_examples_of_pointer_function() {
	
	//various_value_type_templates<i_ptr, c_ptr, &S::f, void_returner_int_passer>(s);

	// various_value_type_templates<i_ptr, "abc", &S::f, void_returner_int_passer>(s); // Instantiation with string
																					  // literal not allowed.
}

//int main() {
//	various_value_type_templates<i_ptr, c_ptr, &S::f, void_returner_int_passer>(s);
//}