/**
* We need to understand when and why an object is created. Consider the following iden
* method. We know that when calling the method, the argument is copied to avoid changing
* the outside parameter. However, when it's returned, it's done using move constructor (rather
* than copy), to avoid an expensive copy. This depends on the fact that the object has a move
* constructor. Morever, it depends on function syntax, whether we're returning reference and
* so forth.
* 
* An object remains an object after its construction is complete and before its destruction.
*/
#include <string>
using namespace std;

string iden(string s) {
	return s;
}