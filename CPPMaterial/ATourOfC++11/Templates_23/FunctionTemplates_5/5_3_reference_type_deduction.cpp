/** Still me:
* Note that the following discussion is the same as what we went through for the for-range loop deduction with
* auto&&.
* 
* Here are the question that I want to answer here:
* 
* 1- Why is it that an rvalue templated type deduced the type of a literal not an rvalue reference? Well. With
* this case, the advantage is that the function argument is deduced as rvalue. For example below, we see that the
* when passing 0 to gets_r_value_reference, type T is deduced as int, but val is deduced as int&&, which is what
* we intend. If the type had been dedeuced as int&&, it would have also been fine, and val would be int&&&&, or
* int&&.
* 
* 2- Why is it that when passing a variable to an rvalue ref templated type, type is deduced as lvalue? But for a
* non-referenced function, the type is not deduced as lvalue? Why don't we get an error in the first case?
* One argument would be that a variable name is an lvalue. Consequently, to make compilation possible, type is 
* dedeuced as lvalue ref. For example below, when passing i, type is deduced as int&, and val as int&&&, or int&.
* I think we have to accept this as is, and consider that as the big guy says, this deduction format helps us avoid
* spurious copies, at the expence of passing an object unintentionally by reference. It appears to be as simple as
* that. The compiler succeeds by setting T = int& together with reference collapse, hence, it does not complain.
* Fortunately, if we introduce a reference based version, that version is chosen!
* Also consider another factor here. If we were to accept an int in the deduction here, it would imply making a cp
* of i. So, the compiler prefers to pass by reference, to avoid making a copy.
* 
* We can't dig any deeper in this subject, and we should accept the big guy's line when he says "Lvalues and rvalues 
* are distinguished by template argument deduction: an lvalue of type X is deduced as an X& and an rvalue as X.".
*/
#include <iostream>
template<typename T>
void gets_r_value_reference(T&& val) {
	val++;
}


template<typename T>
void gets_no_reference(T val) {}

void using_gets_rvalue_ref() {
	int i = 10;

	gets_r_value_reference(10);	// Type is deduced as int, and not int&&. But the variable val has rvalue reference.
	gets_r_value_reference(i);	// Type is deduced as int&. Consequently, val has type int&.
}

