/**
 * Literal types are different from literals, and indicate the following types:
 * 1-	void
 * 2-	scalar type (Me: and pointers to them I suppose! Although we have to add a const as well!!!!)
 * 3-	references
 * 4-	Array of void, scalars or reference types
 * 5-	A class that has a trivial destructor, and one or more constexpr constructors 
 *	that are not move or copy constructors.  Additionally, all its non-static data members and 
	base classes must be literal types and not volatile.
 * 
 * The reason why literal types are important is because "A constexpr variable or function must return a 
 * literal type." Essentially, these are the stuff that we can assign to a constexpr.
 * 
 * 
 */
constexpr int y = 5;
constexpr const int* x = &y;
// constexpr const int* x = 5; // This is not OK, because 5 is a literal.