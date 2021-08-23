/**
 * Notice that ptrdiff_t and size_t definitions are both in the stddef header.
 */

#include <stddef.h>

int main(){
	char* ptr1 = NULL;
	char* ptr2 = NULL;

	size_t char_ptr_sz = sizeof(ptr1);	// 64 bits (8 bytes) on my x86_64 CPU.
	ptrdiff_t n_elements = ptr2 - ptr1;	

	return char_ptr_sz;
}