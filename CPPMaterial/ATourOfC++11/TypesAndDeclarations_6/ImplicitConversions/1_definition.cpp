/**
* The following is from the standard:
* 
* Implicit conversions are performed whenever an expression of some type T1 is used in context that does not 
* accept that type, but accepts some other type T2; in particular:
*	-	when the expression is used as the argument when calling a function that is declared with T2 as 
*		parameter;
*	-	when the expression is used as an operand with an operator that expects T2;
*	-	when initializing a new object of type T2, including return statement in a function returning T2;
*	-	when the expression is used in a switch statement (T2 is integral type);
*	-	when the expression is used in an if statement or a loop (T2 is bool).
*	-	The program is well-formed (compiles) only if there exists one unambiguous implicit conversion 
*		sequence from T1 to T2.
* 
* If there are multiple overloads of the function or operator being called, after the implicit conversion 
* sequence is built from T1 to each available T2, overload resolution rules decide which overload is compiled.
* 
* Note: in arithmetic expressions, the destination type for the implicit conversions on the operands to 
* binary operators is determined by a separate set of rules, usual arithmetic conversions.
*/