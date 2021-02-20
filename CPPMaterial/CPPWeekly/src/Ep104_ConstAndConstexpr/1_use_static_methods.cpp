/**
* If a method does not depend on the status of the class (directly or through class methods), 
* it should be static. The compiler can optimize a static method better.
*/

struct Type {
	int data{};
	void do_something() {};	// This method should be static. Does not depend on class state.

};