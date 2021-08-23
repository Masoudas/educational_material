/**
 * We should not forget the famous difference between static arrays and arrays formed out of pointers. The former
 * is a static allocated array of elements, whereas the latter is a set of pointers, that need to be allocated.
 * Note that the latter requires more space, as it needs space for the pointers, as well the elements. As such,
 * static arrays are faster.
 * 
 * In what follows, we shall initialize an array with pointers both statically and dynamically. We can allocate
 * statically as well, because the pointer will decay to an element pointer.
 */
#include <stdlib.h>

void array_comparisons(){
	int arr[10][5];	// 10 * 5 elements are allocated in the stack.
	int *ptr[10];	// Array of 10 pointers to integer.

	// Notice that access to both arrays is the same, even though they're wildly different.
	int x = ptr[3][2];
	int y = arr[3][2];
}

void static_array_of_pointes(){
	int *arr[3];

	int arr1[] = {1, 2};
	int arr2[] = {3, 4};
	int arr3[] = {5, 6};

	arr[0] = arr1;	// Using the decay property;
	arr[1] = arr2;
	arr[2] = arr3;
}

void dynamic_array_of_pointes(){
	int *arr[3];

	int *arr1 = calloc(2, sizeof(int));	// Allocate and initialize to zero.
	int *arr2 = calloc(2, sizeof(int));	// Allocate and initialize to zero.
	int *arr3 = calloc(2, sizeof(int));	// Allocate and initialize to zero.

	arr[0] = arr1;	// Using the decay property;
	arr[1] = arr2;
	arr[2] = arr3;
}

void conversion_to_array_of_ptrs(int (*arr_s)[2]){	// Pointer to array of two elements.
	int *arr[3];	// Array of three pointers to int.
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++ ){
		arr[i] = (int*)arr_s++;	// Increment and convert. The cast is unnecessary.
	}
}

