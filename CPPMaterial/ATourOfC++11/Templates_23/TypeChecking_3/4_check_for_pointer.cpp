/**
* As we already types are strongly checked, hence we can't assing a derived type to a base type template.
* As it happens, the same check is assigned to pointers for example
*/
#include <string>
#include <vector>

using namespace std;

void dont_assign_to_pointers() {
	// vector<string>* v1{ new string{} }; Error
	// vector<string*> v1{ string{} }; Error
}