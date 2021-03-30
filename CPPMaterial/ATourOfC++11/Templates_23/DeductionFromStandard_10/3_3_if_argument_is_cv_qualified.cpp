/**
* The standard states:
* 
* "If P is a cv-qualified type, the top-level cv-qualifiers are ignored for deduction."
* 
* Note that we're talking about deduction here, and not operation on the values. Because ignoring const does
* not make the passed argument non-const. It's still qualified as const when inside the function, but for
* deduction, its const is removed.
* 
* So, the standard does not specify anything about references for example. So in all of the following cases,
* const is removed from P:
*	-	const T
*	-	const T&
*	-	const T&&
*	-	volatile T
*	-	volatile T&
*	-	volatile T&&
* 
* So, const and volatile don't qualify P.
*/

// Not from standard.
template<typename T>
void with_cv_qualifer(const T t, volatile T v) {
	with_cv_qualifer(5, 5);	// const is P dropped from P1 and P2. {P1, P2} is int.
}