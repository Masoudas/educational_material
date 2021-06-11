/**
* If any of the operands is a pointer, the following rules apply:
*
*	-	A pointer to non-array object is treated as a pointer to the first element of an array with size 1. (me: what?!)
*	-	If the pointer P points to the ith element of an array, then the expressions P+n, n+P, and P-n are pointers of the 
*		same type that point to the i+nth, i+nth, and i-nth element of the same array, respectively. The result of pointer 
*		addition may also be a one-past-the-end pointer (that is, pointer P such that the expression P-1 points to the 
*		last element of the array). Any other situations (that is, attempts to generate a pointer that isn't pointing at 
*		an element of the same array or one past the end) invoke undefined behavior.
*	-	If the pointer P points to the ith element of an array, and the pointer Q points at the jth element of the same 
*		array, the expression P-Q has the value i-j, if the value fits in std::ptrdiff_t. Both operands must point to the
*		elements of the same array (or one past the end), otherwise the behavior is undefined. If the result does not fit 
*		in std::ptrdiff_t, the behavior is undefined.
*	-	In any case, if the pointed-to type is different from the array element type, disregarding cv qualifications, at 
*		every level if the elements are themselves pointers, the behavior of pointer arithmetic is undefined. In 
*		particular, pointer arithmetic with pointer to base, which is pointing at an element of an array of derived 
*		objects is undefined. (Me: I think it implies that if we convert a pointer of array of derived objects to base
*		pointer, and then add to that, we get undefined behavior.)
*	-	If the value ​0​ is added or subtracted from a pointer, the result is the pointer, unchanged. If two pointers point 
*		at the same object or are both one past the end of the same array, or both are null pointers, then the result of 
*		subtraction is equal to (std::ptrdiff_t)0. (ME: A nullptr + 0 is still a nullptr, because zero is null as the 
*		big guy says)
* 
* These pointer arithmetic operators allow pointers to satisfy the LegacyRandomAccessIterator requirements.
*/