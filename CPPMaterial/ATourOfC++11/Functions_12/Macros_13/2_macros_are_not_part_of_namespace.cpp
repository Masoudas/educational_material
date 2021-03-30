/**
* This is me:
* 
* Here's something important to recall about macros. Macros are not part of any namespace. Hence, when using
* them, even if they're defined as part of a namespace (like std for example) they should not be qualified 
* with that.
* 
* In fact, this is the reason why VS pushes their definition to the beginning of the line automatically (
* and does not indent them,) to stress the fact that macros are not part of the namespace.
*/

namespace my_ns {
#define Macro 1;
}

void using_macro() {
	 //	int macro = my_ns::Macro; Error! Macros are not part of the namespace.
	int macro = Macro;	// Now we're cool!
}