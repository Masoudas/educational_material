/**
* Destructors work in the reverse order:
* 1-	First, the destructor executes its own body.
* 2-	Then, it executes its member's destructor.
* 3-	Finally, it executes the destructor of the base.
*/

#include <iostream>
using namespace std;

struct base {
	~base() { cout << "Inside base class destructor" << endl; }
};

struct member {
	~member() { cout << "Inside member class destructor" << endl; }
};

struct destruction_hierarchy : public base {
	member m;

	~destruction_hierarchy() { cout << "inside class destructor" << endl; }
};
//
//int main() {
//	destruction_hierarchy hierarchy{};
//}