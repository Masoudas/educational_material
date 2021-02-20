/**
* We can use the using directive to drag down all members of a namespace.
* A using-directive makes names from a namespace available almost as if they had been 
* declared outside their namespace.
* 
* Note: As a point of interest, checkout the preprocessed file for this file to see what happens when
* you add the using directive.
* 
* Inside a function, using can be used, and we tend to keep such declarations as local as possible.
* However, outside a function, excessive use of using can cause the same problem namespaces were introduced
* to avoid.
* 
* In particular, don’t place a using-directive in the global scope in a header file except 
* in very specialized circumstances
*/
#include <string>

void internal_using_directive() {
	using namespace std;
	string s = "Blah";
}