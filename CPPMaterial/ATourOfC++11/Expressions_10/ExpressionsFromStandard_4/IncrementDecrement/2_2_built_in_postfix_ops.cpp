/**
* The postfix increment and decrement expressions have the form
*	-	expr ++		
*	-	expr --		
*		1) postfix increment (post-increment)
*		2) postfix decrement (post-decrement)
* 
* The operand expr of a built-in postfix increment or decrement operator must be a modifiable (non-const) lvalue of 
* non-boolean (since C++17) arithmetic type or pointer to completely-defined object type. The result is prvalue copy of 
* the original value of the operand. As a side-effect, the expression x++ modifies the value of its operand as if by 
* evaluating x += 1 for non-boolean operands (until C++17), and the expression x-- modifies the value of its operand as if 
* by evaluating x -= 1. All arithmetic conversion rules and pointer arithmetic rules defined for arithmetic operators 
* apply and determine the implicit conversion (if any) applied to the operand as well as the return type of the expression.
* 
* If the operand of the post-increment operator is of type bool, it is set to true (deprecated). (until C++17)
* 
* In overload resolution against user-defined operators, for every optionally volatile-qualified arithmetic type A other 
* than bool, and for every optionally volatile-qualified pointer P to optionally cv-qualified object type, the following 
* function signatures participate in overload resolution:
*
*	-	A operator++(A&, int)
*	-	bool operator++(bool&, int)		(deprecated)(until C++17)
*	-	P operator++(P&, int)
*	-	A operator--(A&, int)
*	-	P operator--(P&, int)
*/

#include <iostream>

void examples_of_increment_and_decrement()
{
    int n1 = 1;
    int n2 = ++n1;
    int n3 = ++ ++n1;
    int n4 = n1++;
    //  int n5 = n1++ ++;   // error
    //  int n6 = n1 + ++n1; // undefined behavior
    std::cout << "n1 = " << n1 << '\n'
        << "n2 = " << n2 << '\n'
        << "n3 = " << n3 << '\n'
        << "n4 = " << n4 << '\n';
}

