/**
 * Unless we're passing a ref, everything sent to a function is copied (using copy initilzation
 * construct). Implicit and user defined casts are performed when necessary.
 * 
 * When we're sending a reference type, no copying takes place (or assignment for that matter). The 
 * object is directly given to the function.
 * 
 * Given the rules of references, when passing a non-const reference, no conversion can
 * take place.
 */
#include <string>

void passing_by_reference(int& ref) {
	int x = 5;
	passing_by_reference(x);	// No assignment or copy occurs when passing by reference.
	// passing_by_reference(5); Impossible. Rvalue cannot be assigned to lvalue
	// passing_by_reference(int{}); Impossible. Rvalue cannot be assigned to lvalue
	// passing_by_reference(float{ 5 });	Impossible. Conversions are not allowed.
	
}
