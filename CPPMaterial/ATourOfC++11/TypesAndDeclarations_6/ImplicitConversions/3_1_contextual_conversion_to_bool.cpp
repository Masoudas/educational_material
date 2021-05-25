/**
* In the following contexts, the type bool is expected and the implicit conversion is performed if the 
* declaration bool t(e); is well-formed (that is, an explicit conversion function such as explicit 
* T::operator bool() const; is considered). Such expression e is said to be contextually converted to bool.
*	-	the controlling expression of if, while, for;
*	-	the operands of the built-in logical operators !, && and ||;
*	-	the first operand of the conditional operator ?:;
*	-	the predicate in a static_assert declaration;
*	-	the expression in a noexcept specifier;
*	-	the expression in an explicit specifier
* 
* Me: We shall elaborate on the first 4 next. Then, we shall given another weird contextual conversion.
*/