/**
 * 	void* realloc(void*, size_t)
 * Reallocates the given area of memory. It must be previously allocated by malloc(), calloc() or realloc() and not yet 
 * freed with a call to free or realloc. Otherwise, the results are undefined. 
 * 
 * The reallocation is done by either:
 * 		a) expanding or contracting the existing area pointed to by ptr, if possible. The contents of the area remain 
 * 		   unchanged up to the lesser of the new and old sizes. If the area is expanded, the contents of the new part of 
 * 		   the array are undefined.
 * 		b) allocating a new memory block of size new_size bytes, copying memory area with size equal the lesser of the 
 * 		   new and the old sizes, and freeing the old block.
 * 
 * If there is not enough memory, the old memory block is not freed and null pointer is returned. If ptr is NULL, the 
 * behavior is the same as calling malloc(new_size).
 * 
 * If new_size is zero, the behavior is implementation defined (null pointer may be returned (in which case the old 
 * memory block may or may not be freed), or some non-null pointer may be returned that may not be used to access 
 * storage).
 * 
 * realloc is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not 
 * any static storage.
 * 
 * A previous call to free or realloc that deallocates a region of memory synchronizes-with a call to any allocation 
 * function, including realloc that allocates the same or a part of the same region of memory. This synchronization 
 * occurs after any access to the memory by the deallocating function and before any access to the memory by realloc. 
 * There is a single total order of all allocation and deallocation functions operating on each particular region of 
 * memory.
 */