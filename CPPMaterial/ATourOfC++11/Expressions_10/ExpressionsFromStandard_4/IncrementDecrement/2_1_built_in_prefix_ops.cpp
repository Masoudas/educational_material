/**
* Note: Essentially, don't increment bool. Why would you? Even though promotion to int occurs, but why do it! Also note 
* that increment ops work on lvalues. Hence, we can't apply them to rvalues.
* 
* The prefix increment and decrement expressions have the form:
*	-	++ expr		
*	-	-- expr		
*		1) prefix increment (pre-increment)
*		2) prefix decrement (pre-decrement)
* 
* The operand expr of a built-in prefix increment or decrement operator must be a modifiable (non-const) [lvalue of 
* non-boolean (since C++17)] arithmetic type or pointer to completely-defined object type. The expression ++x is exactly 
* equivalent to x += 1 for non-boolean operands (until C++17), and the expression --x is exactly equivalent to x -= 1, 
* that is, the prefix increment or decrement is an lvalue expression that identifies the modified operand. All arithmetic 
* conversion rules and pointer arithmetic rules defined for arithmetic operators apply and determine the implicit 
* conversion (if any) applied to the operand as well as the return type of the expression.
*
* If the operand of the pre-increment operator is of type bool, it is set to true (deprecated). (until C++17)
* 
* In overload resolution against user-defined operators, for every optionally volatile-qualified arithmetic type A other 
* than bool, and for every optionally volatile-qualified pointer P to optionally cv-qualified object type, the following 
* function signatures participate in overload resolution:
*	-	A& operator++(A&)
*	-	bool& operator++(bool&) (deprecated)(until C++17)
*	-	P& operator++(P&)
*	-	A& operator--(A&)
*	-	P& operator--(P&)
*/

// This is me!
int returns_int() {
	// returns_int()++; Error! Incrementing an lvalue object.
	return {};
}