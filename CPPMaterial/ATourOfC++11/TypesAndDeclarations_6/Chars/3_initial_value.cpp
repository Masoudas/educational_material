/**
* The inital value of char is of course implementation dependent. 
* 
* Me: Of course, this also depends on whether or not we use brackets.
*/

void various_initializations() {
	char stack;	// Random value on stack. Default initialization.
	char* mem = new char;	// Random value in memory. Fundamental types are never initalized.

	char stack_init{};	// Default initialization. Value is \0 (?)
	char* mem_init = new char{};	// \0?
}
