/**
* Me: In this section, we're going to talk about conversions with qualified types, particularly cv qualified
* types.
* 
*	-	A prvalue of type pointer to cv-qualified type T can be converted to a prvalue pointer to a more 
*		cv-qualified same type T (in other words, constness and volatility can be added).
*	-	A prvalue of type pointer to member of cv-qualified type T in class X can be converted to a prvalue 
*		pointer to member of more cv-qualified type T in class X.
* 
* "More" cv-qualified means that
*	-	a pointer to unqualified type can be converted to a pointer to const;
*	-	a pointer to unqualified type can be converted to a pointer to volatile;
*	-	a pointer to unqualified type can be converted to a pointer to const volatile;
*	-	a pointer to const type can be converted to a pointer to const volatile;
*	-	a pointer to volatile type can be converted to a pointer to const volatile
* 
*/