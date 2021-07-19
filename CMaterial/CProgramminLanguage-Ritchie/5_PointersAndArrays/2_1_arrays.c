/**
 * Note that the mere declaration 'a[n]' defines and allocates memory for the array of the given size. We can add
 * an initialization by appending it with brackets, but that's a different story.
 * 
 * As we may recall, by defining 'int a[10]' these assignments are meaningful or not:
 * int* ip = *a[10]
 * int* ip = a;	// Implicit cast to int pointer.
 * int* ip = &a;	// Error! a is const pointer to array of 10 ints.
 * int const *(ip[10]) = &a	// I think!
 * 
 * Recall that as such, a construct like a++ is not valid, but ip++ is valid. mostly because an array name is not
 * a variable (partly because it's a constant.)
 */
