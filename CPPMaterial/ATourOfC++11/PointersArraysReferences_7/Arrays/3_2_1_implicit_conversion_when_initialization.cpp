/* All me:
* 
* Bjarne says: " If initializer specifies not enough arguments, the rest are initialize to zero.
* All array elements that are not initialized explicitly are zero-initialized (or empty initialized). "
* 
* 
* As we already know, an array can be thought of as a set of variables inside memory. When saying T arr[],
* its like we're saying:
* T arr1 = ... 
* T arr2 = ...
* ....
* 
* When we put the {} in front of array declaration, every object is initialized to its default constructor.
* Now because of the above two notions:
* 
* 1-	{{}, {}} is equivalent to {}, or default constructor.
* 2-	Implicit conversions take place when we initialize. For example string arr[2] = {"a"} means the first
*	element is implcitly initialized to "a", whereas second to default.
*/
#include <iostream>
#include <string>
using namespace std;

void array_implicit_and_explicit_initialization() {
	string arr[3] = { "a", string{"b"} };

	for (int i = 0; i < 3; i++) {
		cout << "arr[" << i << "] is: " << arr[i] << endl;
	}
}

//int main() {
//	array_implicit_and_explicit_initialization();
//}