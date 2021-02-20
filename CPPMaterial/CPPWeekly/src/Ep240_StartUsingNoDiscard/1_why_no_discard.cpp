/**
* Sometimes we want to warn the user not to discard the return value of a function, which probably indicate
* they're using the wrong method. For example, with a simple list, the method empty() is no discard, which
* shows whether the list is empty or not. However, clear() is not, meaning it clears the list. Sometimes,
* we mix empty and clear. Hence, if we don't discard the return of empty, we don't make this mistake!
* 
* We may also write some message in the no discard as of C++20.
*/

#define _NoDiscard [[nodiscard]]	// Something typically done in STL.

_NoDiscard int method() {
	method();	// See the warnings below!
	return 0;
}

[[nodiscard("Yo man, don't discard!")]] int method1() {
	method1();
	return 0;
}