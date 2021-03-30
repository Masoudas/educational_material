/**
* The standard states that "If P is a reference type, the type referred to by P is used for deduction."
* 
* So, because the standard does not qualify this sentence with rvalue and lvalue, I conclude that:
*	- If the argument is T&, or const T&, then P is equal to whatever is deduced for T.
*	- If the argument is const T&&, then P is deduced as whatever is deduced for T.
*	- T&& is a special case, which we discuss next.
*/
