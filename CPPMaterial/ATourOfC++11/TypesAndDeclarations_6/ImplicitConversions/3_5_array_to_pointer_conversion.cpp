/**
* We touch the following briefly. More crazy stuff can be found under the section "Array to pointer conversion"
* in the "implicit conversion" part of the standard.
* 
* An lvalue or rvalue of type "array of N T" or "array of unknown bound of T" can be implicitly converted to a 
* prvalue of type "pointer to T". If the array is a prvalue, temporary materialization occurs. (since C++17) 
* The resulting pointer refers to the first element of the array (see array to pointer decay for details.)
*/