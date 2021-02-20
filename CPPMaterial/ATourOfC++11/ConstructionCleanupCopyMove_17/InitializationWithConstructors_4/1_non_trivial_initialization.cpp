/**
* If a constructor is declared for a class, some constructor will be used for every object.
* (Me: In other word, an object cannot be created without using a constructor).
* This includes declaring a simple object as follows:
* T a;
*
* Even for this, memory will be allocated. Now, if there's no proper empty initializer, this will throw
* us an error. Note that this does not depend on whether invariants are initialized (without constructor).
*
* Note that defining non-trivial constructor causes default constructor to disappear. However, copy
* constructor remains in place.
*/
struct no_trivial_constructr {
	int i;

	no_trivial_constructr(int i) : i(i) {}
};

struct initialized_invariants {
	int i = 10;
	initialized_invariants(int j) {}
};

void initializatation_with_non_default_constructors() {
	// no_trivial_constructr c1;	Error! has no trivial initialization.
	// no_trivial_constructr c1{}; Error!

	// initialized_invariants c2; Error! Even though properly initialized, has non-trivial constructor only.
	// initialized_invariants c2{}; Error! 


}