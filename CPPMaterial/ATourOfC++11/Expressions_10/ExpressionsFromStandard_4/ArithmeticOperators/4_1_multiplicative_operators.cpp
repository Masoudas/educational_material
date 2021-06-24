/**
* The binary multiplicative arithmetic operator expressions have the form
*	-	lhs * rhs	(1)	
*	-	lhs / rhs	(2)	
*	-	lhs % rhs	(3)	
*	1) multiplication) For the built-in operator, lhs and rhs must both have arithmetic or unscoped enumeration type.
*	2) division) For the built-in operator, lhs and rhs must both have arithmetic or unscoped enumeration type.
*	3) remainder) For the built-in operator, lhs and rhs must both have integral or unscoped enumeration type
* 
* ME: recall that with enumerations, the result of any ops is always cast implicitly to a variable of the underlying
* type.
* 
* For all three operators, the usual arithmetic conversions are performed on both operands and determine the type of the 
* result.
*/