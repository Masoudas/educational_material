/**
* Constructor builds a class from bottom-up:
* 1-	It first invokes its base class constructor.
* 2-	Second, it invokes the constructors of its members.
* 3-	Finally, it executes its own body.
* 
* Question: If the constructors of members are called, why would an int get a random value
* in a class? Perhaps we should exclude built-in types.
* 
* Constructors execute member and base constructors in declaration order (not the order of initializers): 
* if two constructors used a different order, the destructor could not (without serious overhead) 
* guarantee to destroy in the reverse order of construction.
*/
#include <iostream>
using namespace std;

struct base {
	base() { cout << "Inside base class constructor" << endl; }
};

struct member {
	member() { cout << "Inside member class constructor" << endl ; }
};
struct construction_hierarchy : public base {
	member m;
	int i;
	construction_hierarchy() { cout << "inside class constructor" << endl; }
};

//int main() {
//	construction_hierarchy hierarchy{};
//
//	cout << hierarchy.i << endl;
//}