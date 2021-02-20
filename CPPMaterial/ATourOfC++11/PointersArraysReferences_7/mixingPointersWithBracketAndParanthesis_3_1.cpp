/**
 * !!!THIS IS INCOMPLETE AND SHOULD BE IMPROVED!!!
 * 
 * There were a couple of rules. 
 * 1- Start with the type name (or where it should be).
 * 2- Go to right when you can, go the left when you must.
 * 
 * int* a[5]; a is (precedence, go right) an array of 5 pointers to int.
 * 
 * int a*[5]; a is a pointer to array of five integers.
 * 
 * const int * a; // a is a pointer to integer constant;
 * int const * a; // Again, a is a pointer to constant integer.
 * int * const a; // a is a constant pointer to integer.
 * 
 * char *(*fp)( int, float *) // fp is a pointer to function of type ... that returns a pointer to char.
 * 
 * int **(*p)[5]; // p is a pointer to array of five pointer to pointers.
 * 
 */ 
