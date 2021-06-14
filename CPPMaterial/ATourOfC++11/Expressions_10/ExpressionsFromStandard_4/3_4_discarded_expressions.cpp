/**
* Me: I wonder whether this applies to an expression such as a.f() for example, which is used for its side effect, and
* not necessarily for the return value of f.
* 
* A discarded-value expression is an expression that is used for its side-effects only. The value calculated from such 
* expression is discarded. Such expressions include the full expression of any expression statement, the left-hand operand 
* of the built-in comma operator, or the operand of a cast-expression that casts to the type void.
* 
* Array-to-pointer and function-to-pointer conversions are never applied to the value calculated by a discarded-value 
* expression. The lvalue-to-rvalue conversion is applied if and only if the expression is a volatile-qualified glvalue and 
* has one of the following forms (built-in meaning required, possibly parenthesized:)
* 
*	-	id-expression
*	-	array subscript expression
*	-	class member access expression
*	-	indirection
*	-	pointer-to-member operation
*	-	conditional expression where both the second and the third operands are one of these expressions,
*	-	comma expression where the right operand is one of these expressions.
* 
* In addition, if the lvalue is of volatile-qualified class type, a volatile copy-constructor is required to initialize 
* the resulting rvalue temporary. (Me: a class can be volatile?!)