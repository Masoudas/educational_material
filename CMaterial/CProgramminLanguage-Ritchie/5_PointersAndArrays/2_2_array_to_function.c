/**
 * Recall that when an array is passed to a function, the location of the first element is passed to it. Hence,
 * for one dim arrays, a cast to element pointer takes place. 
 * 
 * Note that essentially, when a pointer is passed, we can index backwards as well, so long as the indexes are
 * valid memory locations.

void f(int* p){
	p[-1] = 10;	// Or *(p-1) = 10;
} 

f(&arr[1]);	// Passing index 1 instead of index 0.

 *  
 * For multi-dim arrays, the last dimentsion is always skipped.
 */

void pass_array(int arr[5][]){	// Pointer to an array that has five pointers to int.
	
}