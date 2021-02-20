/*
* As we discussed in 2, for arrays, {} initializes array elements using their default constructors.
* like int a[2]{} initializes to {0,0};
* 
* Never forget that not using {} means random initialization!
* 
* For user defined types, if a default constructor is supplied, it will be used. Otherwise, such construction
* is impossible (even with bracketless construction, such as T t[10]). 
* 
* (ME: Note: With built-in types, we always use a constructor when initialization. Hence, an array such
* as T t[n] must be initialized with default constructor, because it's a built-in type. Hence, if there's
* no default constructor, we can't initialize like this).
* 
* Finally, note that we can partially initialize some elements of the array.
*/
#include <string>
using namespace std;

struct default_constructor {
	int i;
	string s;
};

struct non_default_constructr {
	string s;
	non_default_constructr(string s): s(s){}
};

void initializing_an_array_of_objects() {
	default_constructor a1[2];	// Random initialization
	default_constructor a2[2] = {};	// Initialize with default constructor;

	//non_default_constructr a3[2];	// Empty initializaiton is not possible!!! No default constructor.
	// non_default_constructr a3[2] = {};	Error! Has no default constructor
	non_default_constructr a4[2] = { string{""}, string{"s1"} };
}