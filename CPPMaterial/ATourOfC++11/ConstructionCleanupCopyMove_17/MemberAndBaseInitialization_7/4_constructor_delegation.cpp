/**
* If the body of two constructors is the same, we can extract a method to avoid repetition, and
* call the method from both constructros.
* 
* The other method is to delegate one constructor to another. It should be called like a member initializer.
* We call a constructor that calls another constructor a delegating constructor (or a forwarding constructor).
* 
* Note that we can't use constructor delegation and member initializers at the same time.
* 
* We should note that we can't call the constructor in the body of another constructor. That would imply 
* that we're creating another object as shown below.
*/

struct delegating_constructor {
	delegating_constructor() : delegating_constructor(0){}
	delegating_constructor(int i){}
};

struct not_delegating_constructor {
	// not_delegating_constructor() : {not_delegating_constructor{ 0 }; } This is not delegation
	not_delegating_constructor(int i) {}
};