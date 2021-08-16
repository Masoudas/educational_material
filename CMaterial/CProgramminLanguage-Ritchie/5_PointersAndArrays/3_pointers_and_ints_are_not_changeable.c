/**
 * Recall that pointers and integers are not interchangeable. Hence, we cannot assign an integer to a pointer, or
 * vice versa. The only exception here is zero, that can be assigned to a pointer. We can however explicitly cast
 * a pointer to integer to see its value.
 * 
 * Also, recall that NULL is defined in the stdio.h header.
 * 
 * Also recall that the difference between two pointers is the ptrdiff_t type, which is in the stddef header.
 * 
 * However, as we recall, pointers can be mixed with ints with + and - operators only.
 */

void pointer_integer_assignment(){
	// int* p = 10; Error
	int v = 10;
	int* p = &v;

	//int address_val = p;	// Error! No cast to int is allowed.
	int address_val = (int)p;
}