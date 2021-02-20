/*
* The syntax for calling the base constructor is the same as that of calling a member constructor.
* 
* If not explicity specified, base must have default constructor. Otherwise, we need to explicitly 
* specify the base class constructor.
*/

struct b1 {};

struct b2 : b1 {
	b2(int i){}	// No need to explicitly call b1 structors, although we can.
	b2(int i, int j){}
};

struct b3 : b2{}; // This morron does not show warning here! However, default constructor is
						// deleted. Hence, the object can't be initialized!!! We need to add constructors.


struct b3_1 : b2 {
	b3_1() : b2(10) {}; // Fine, calling b2 constructor.
};

void intitializing_hierarchy() {
	// b3 c1{}; No it sees that the class can't be constructed, and it throws an error!!!
	b3_1 c2{};
}
