/**
 * As we already know, when an array is passed to a function, the pointer decays to the underlying type.
 * Hence, for example, an array of chars decays to a pointer to char. 
 * 
 * With multi-dim arrays, the same decay happens. That is, char[][] decays to a pointer to an array of the
 * column size. Hence, we write either of the following notation:
 
 void f(char (*)[12] );	// Pointer to an array of 12 chars.
 void f(char arr[2][12]);	
 void f(char arr[][12]);

 *
 */