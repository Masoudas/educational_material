/**
* The operands of any operator may be other expressions or primary expressions (e.g. in 1+2*3, the operands of operator+ 
* are the subexpression 2*3 and the primary expression 1).
* 
* Primary expressions are any of the following:
*	-	Literals (e.g. 2 or "Hello, world")
*	-	Id-expressions, including:
*		-	suitably declared unqualified identifiers (e.g. n or cout), and
*		-	suitably declared qualified identifiers (e.g. std::string::npos)
*	-	Lambda-expressions (C++11)
*	-	Fold-expressions (C++17)
*	-	Requires-expressions (C++20)
* Any expression in parentheses is also classified as a primary expression: this guarantees that the parentheses have 
* higher precedence than any operator. Parentheses preserve value, type, and value category.
*/