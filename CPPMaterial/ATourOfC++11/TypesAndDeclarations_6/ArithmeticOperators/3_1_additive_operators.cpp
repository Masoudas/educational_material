/**
* An expression like "lhs + rhs	(1)" or "lhs - rhs	(2)."
* 
* (1) addition:
*	For the built-in operator, lhs and rhs must be one of the following:
*		-	both have arithmetic or unscoped enumeration type. In this case, the usual arithmetic conversions are 
*			performed on both operands and determine the type of the result.
*		-	one is a pointer to completely-defined object type, the other has integral or unscoped enumeration type. In 
*			this case, the result type has the type of the pointer.
* 
* (2) subtraction:
*	For the built-in operator, lhs and rhs must be one of the following:
*		-	both have arithmetic or unscoped enumeration type. In this case, the usual arithmetic conversions are 
*			performed on both operands and determine the type of the result.
*		-	lhs is a pointer to completely-defined object type, rhs has integral or unscoped enumeration type. In this 
*			case, the result type has the type of the pointer.
*		-	both are pointers to the same completely-defined object types, ignoring cv-qualifiers. In this case, the 
*			result type is std::ptrdiff_t. (Me: The famous case of distancing two pointers. Note that pointers can only
*			be mixed with integers, and necessarily ints! And if smaller than int, promoted to int!)
*/