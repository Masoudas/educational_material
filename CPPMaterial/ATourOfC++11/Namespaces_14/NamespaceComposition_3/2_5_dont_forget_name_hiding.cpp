/**
* As a reminder, don't forget that if we REDECLARE something that was already defined in another scope,
* we're hiding it in the new scope. A simple example is defining a new variable in a for loop that has
* the same name as the outer of the loop.
* 
* Note the distinction between declare and implement. 
* 1-	When we redeclare we hide!
* 2-	If we declare the same entity in both scope and then drag the other scope inside our new scope,
*	then we get a run-time error.
*/
int i = 20;
int j = 30;

namespace decl_v_impl {
	int i = 20;	// Fine, no dragging from outside; Hides the global i

	// using ::i; Error, declaration conflict with our i. Both can be accessed with i!
}

