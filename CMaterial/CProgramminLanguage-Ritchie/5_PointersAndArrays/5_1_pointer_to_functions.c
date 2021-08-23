/**
 * Pointer to functions can be assigned to arrays, returned from functions, or passed to functions.
 * 
 * Note that if we define a pointer to function as a type (using typedef,) we need to instantiate it like a normal
 * variable. Otherwise, the pointer to function when defined must be assigned to at the time of definition, and
 * can't be just declared. When using typedef, notice that the type name does not appear independently like normal
 * types, but rather appears after the pointer.
 * 
 * Note: Why do we interpret int *f() as a function that returns a pointer, but int (*f)() as a pointer to function
 * that's called f? Essentially, because paranthesis have a higher priority than prefix operators.
 */

typedef int (*main_ptr_t)(int, char**);

int main(){
	int (*f_ptr)(int, char**) = main;

	main_ptr_t t = f_ptr;
}
 