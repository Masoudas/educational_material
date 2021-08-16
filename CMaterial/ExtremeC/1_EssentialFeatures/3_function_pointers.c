/**
 * Recall that a function pointer name has to be defined inside the (*). Therefore, an instance of the function pointer
 * is defined together with its type. This is because in C, as opposed to C++, we can't have custom types (In there,
 * we normally define function pointers as an alias or a type, and reuse them.)
 * 
 * However, the work-around for this is to use typedef. But even in this case, we need to put the type name inside 
 * the paranthesis (and not after it like we always do.) Then, however, we can have several instances of that type.
 * Notice that in C, the type alias usually ends with _t.
 * 
 * Recall that just like a normal pointer, it's important to initialize a function pointer properly as well.
 * 
 * 
 */

typedef  int (*my_ptr_t)(int, int);

int get_ptr(int (*ptr)(int, int)){	// The syntax is not int (*)(int, int) ptr!
	// void (*)(int, int) ptr; Error! Instance and definition are not separable. No custom types in C.
	int (*f_ptr)(int, int) = ptr;

	my_ptr_t instance_1 = ptr;
	my_ptr_t instance_2 = ptr;

	return f_ptr(1, 1);
}

/** 
 * An equivalent definition in C++:
 using ptr = int (*)(int, int);

void f(){
	ptr x;
}
 */