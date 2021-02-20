/**
 * An object is simply a contiguous storage in memory (not necessarily an object of a class).
 * An lvalue has an address the program can access.
 * This could be a variable name, array elements, function calls that return 
 * an rvalue, bit fields, class members, etc. 7 is not an lvalue. j * 4 is not an lvalue, 
 * because it does not refer to an object location in memory. The reference is an lvalue, because it
 * points to an address in memory (although we can't change its address value).
 * In these statements:
 * int i = 2, j = 1;
 * ((i < 3) ? i : j) = 7; The function returns an lvalue
 * 
 * An lvalue can refer to a constant. An lvalue that is not constant is called a MODIFIABLE LVALUE.
 * 
 * Something that is not an lvalue is an rvalue. For example, the return value of a function is an rvalue.
 * The return value of a function is an r value. The rvalue reference
 * is of course is an rvalue.
 * 
 * (Me: simply put, lvalue is anything that can be on the left side of an expression. rvalue
 * is anything that is not lvalue. Not all lvalues can be on the left side though. For example,
 * a constant.)
 */