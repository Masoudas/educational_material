/**
* According to the standard:
* Executes a for loop over a range.
* Used as a more readable equivalent to the traditional for loop operating over a range of values, such as all elements in a 
* container.
* 
* Syntax:
*	- attr(optional) for ( range_declaration : range_expression ) loop_statement		(until C++20)
*	- attr(optional) for ( init-statement(optional); range_declaration : range_expression ) loop_statement (since C++20)
* 
*	attr					-	any number of attributes
*	init-statement(C++20)	-	either an expression statement (which may be a null statement ";")
*								a simple declaration, typically a declaration of a variable with initializer, but it may 
*								declare arbitrarily many variables or be a structured binding declaration.
*								Note that any init-statement must end with a semicolon ;, which is why it is often described 
*								informally as an expression or a declaration followed by a semicolon.
*	range_declaration		-	a declaration of a named variable, whose type is the type of the element of the sequence 
*								represented by range_expression, or a reference to that type. Often uses the auto specifier 
*								for automatic type deduction
*	range_expression		-	any expression that represents a suitable sequence (either an array or an object for which 
*								begin and end member functions or free functions are defined) or a 
*								braced-init-list.
*	loop_statement			-	any statement, typically a compound statement, which is the body of the loop
* 
* The range based for loop is equivalent to the following expression:
* 
* auto && __range = range_expression ;
* auto __begin = begin_expr ;
* auto __end = end_expr ;
* for ( ; __begin != __end; ++__begin) {
*	range_declaration = *__begin;	// The part where the loop variable is declared.
*	loop_statement
* }
* 
* Note begin and expression are calculated as follows:
* 1- If range expression is array type, it will be the start and end of the array.
* 2- If range_expression is an expression of a class type C that has both a member named begin and a member named end 
*	(regardless of the type or accessibility of such member), then begin_expr is __range.begin() and end_expr 
*	is __range.end();
* 3- Otherwise, begin_expr is begin(__range) and end_expr is end(__range), which are found via argument-dependent lookup 
* (non-ADL lookup is not performed).
* 
* The standard indicates that the safest way to use a for loop is to write for (auto&& val : range). Why is this
* the case? This is because if range is a temprary, then the iterator might return by rvalue reference. Therefore,
* it's best to use auto&& so that if this is the case, then the value would be taken by rvalue reference (and no
* exception is raised), otherwise, auto&& will turn into an lvalue (Of course, if we don't want to modify the
* range, we can always write a plain auto). 
*/
#include <initializer_list>
#include <string>
#include <iostream>
#include <unordered_map>

void range_based_can_be_structured_binding() {
	std::unordered_map<int, int> mymap{};
	mymap[1] = 1;
	mymap[2] = 2;
	mymap[0] = 3;

	for (auto& [first, second] : mymap) {
		std::cout << "Key is: " << first << " and value is: " << second << '\n';
	}
}

void for_range_accepts_braced_initialier_list() {
	for (auto i : {1, 2, 3, 4}){ // Note that the life-time of the temp objects are extended inside the loop!
								// Not after
	}

	struct S {};
	S s{};
	for (auto&& i : { S{}, S{}, S{} }) {
		//s = std::move(i);	// Error! For one thing, moving a loop temp inside s. More interestingly, 
							// each i is const, and I don't know why that is, but moving const object is wrong!
	}
	
}

/**/
void loop_variable_can_be_r_value_and_its_the_safest() {
	std::string vec[] = { "a", "b" };
	
	for (auto&& i : vec) { i = "changed by accessing rvalue ref"; }

	std::cout << "vec elements changed through rvalue ref: " << vec[0];
}

void for_range_with_initialization_statement() {
	int v[] = { 1, 2, 3, 4 };

	for (int i = 0; auto n: v) {
		// ...
	}
}

struct S{
	int* begin() { return nullptr; }

	int* end() { return nullptr; }

	int* operator++() { return nullptr; }
	int operator*() { return 0; }
	bool operator!=(const S&) { return true; }
};

void for_range_for_custom_type() {
	S s{};
	for (auto &val : s) {}
}


//int main() {
//	range_based_can_be_structured_binding();
//}