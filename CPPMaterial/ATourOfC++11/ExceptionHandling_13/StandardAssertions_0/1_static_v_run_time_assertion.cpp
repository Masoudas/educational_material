/**
* Statics asserts are compile-times assertions that can be invoked using the static_assert command. On the other
* hand, run-time assertions are invoked by including the cassert header, which was originally in the C standard 
* library as <assert.h>.
*  
* Note that for static_assert, we don't need any extra inclusion.
*/

#include <cassert>
void assertion_examples() {
	static_assert(2 < 5, "Checked during compile time.");
	
	// Comes to life with inclusion of cassert header.
	assert(2 < 42);	// Checked during run-time.
}
