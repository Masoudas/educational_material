/**
 * We should remind here that pointers in particular should always be initialized, even with NULL. Never leave a pointer
 * uninitialized, because it's assigned a random variable on stack (recall the disaster that happended with Qt class!)
 * 
 * 
 * In every platform, we have one single unit of memory and all pointers store the addresses inside that memory. So, all 
 * pointers should have equal sizes in terms of bytes. But this doesn't mean that all of them have equal arithmetic step 
 * sizes. As we mentioned earlier, the arithmetic step size of a pointer is determined by its C data type. For example,
 * an int pointer has the same size as an int pointer, but the steps taken by them are different.
 * 
 * Once again, don't forget that pointers are not directly convertible to integral values. We need to perform a c-style
 * cast to do so, to print them for example.
 * 
 * Also recall that the value of a pointer is in bytes. Hence if an int pointer has the value 1, then adding one to it
 * will put it at 5 (assuming int size is 4 bytes.)
 * 
 * Reminder: malloc and free are not part of the C syntax, and they should be defined from the stdlib header.
 * 
 */

#include <stdlib.h>

int main(){
	int* ptr = (int*)malloc(sizeof(int) * 4);	// Allocate an array of four pointers.
	if (ptr){	// Recall that there are no exceptions in C. So always check for a valid pointer.

	}
}