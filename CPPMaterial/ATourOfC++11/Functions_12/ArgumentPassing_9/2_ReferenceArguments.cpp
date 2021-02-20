/**
 * As we know f(int& x) changes the value of x. Hence, passing by reference should be done
 * with cautious (I'd say). Pefer passing as constant ref! Passing a const ref allow us to pass
 * literals, and types that require conversion as well.
 * 
 * We should try and do the same with pointers as well.
 * 
 * The absence of const in the declaration of a reference argument is taken as a statement of intent to modify the variable.
 * 
 * void g(Large& arg); // assume that g() modifies arg
 * 
 * The same situation happens with pointers: 
 * int strlen(const char∗); //number of characters in a C-style string
 * char∗ strcpy(char∗ to, const char∗ from); // copy a C-style string
 * int strcmp(const char∗, const char∗); //compare C-style strings
 *
 *
 * Note that the semantics of argument passing are different from the semantics of assignment. In other words,
 * when a reference is passed, no assignment takes place.
 * 
 * Bjarne says "Please note that for a template argument T, the template argument type deduction rules give T&&
 * a significantly different meaning from X&& for a type X (§23.5.2.1)."
 */

/*
* As we already know, a reference cannot be initialized with a literal, constant (literal being an rvalue does not have an address
* the reference can hold) and an argument that requires conversion.
* Why is this the case? Because otherwise we would have modified a temporary (like for example passing a 
* double to float requires creating a temporary float, and then that temp would have been changed).
*
*/
#include <vector>
using namespace std;

void Wrongful_Reference_Initialization(float i, const int j) {
	// int& a = 12; An rvalue does not have a memory address
	// int& b = i; Assignment to reference involving conversion is not possible (why?)
	// int& c = j;	This we knew was impossible, because reference can change the value of constant this way

	const int& a = i;
	const int& b = 12;
	const int& c = j;
}

/* The same rules apply with functions too.*/
void function_that_accepts_reference(int& ref) {

}

void passing_to_function_that_accepts_ref(float i, const int x) {
	//function_that_accepts_reference(i); Impossible. A conversion takes place.
	// function_that_accepts_reference(12); Impossible. rvalue is passed to ref.
	// function_that_accepts_reference(x); Impossible. passing a constant to ref argument.
}

/* 
* As we know, r and l values can be assigned to their own references. Hence, in the following program,
notice when a function with r or l value reference is called.
*/
void method_accepting_reference_type(vector<int>& v) {}
void method_accepting_reference_type(vector<int>&& v) {}
void method_accepting_reference_type(const vector<int>& v) {} // This override is possible?

void calling_reference_based_argument_methods() {
	vector<int> v{};
	const vector<int> v1{};
	method_accepting_reference_type(v);	// Calling lvalue ref.
	method_accepting_reference_type(v1);	// Calling const lvalue ref.
	method_accepting_reference_type(move(v));	// Calling rvalue method.
	method_accepting_reference_type(vector<int>{1, 2, 3, 4});	// Calling rvalue ref.
}