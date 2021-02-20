/**
* Going away from static methods, it's always a good practice to use constant class methods. Of course this
* should only be done with methods that are not changing class invariants.
* 
* Don't forget the use of mutable keyword too.
*/

struct Type {
	int data{};
	int do_something() const { return data + 4; };	// This method should be static. 
													// Does not depend on class state.
};