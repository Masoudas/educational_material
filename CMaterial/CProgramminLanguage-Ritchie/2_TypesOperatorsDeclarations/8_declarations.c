/**
 * All variables must be declared before use, although certain declarations can be made implicitly by content. A 
 * declaration specifies a type, and contains a list of one or more variables of that type, as in:
 
int lower, upper, step;
char c, line[1000];

 * The latter form takes more space, but is convenient for adding a comment to each declaration for subsequent 
 * modifications.
 * 
 * If the variable in question is not automatic, the initialization is done once only, conceptionally before the 
 * program starts executing, and the initializer must be a constant expression. An explicitly initialized 
 * automatic variable is initialized each time the function or block it is in is entered; the initializer may be 
 * any expression. External and static variables are initialized to zero by default. Automatic variables for which 
 * is no explicit initializer have undefined (i.e., garbage) values.
 */