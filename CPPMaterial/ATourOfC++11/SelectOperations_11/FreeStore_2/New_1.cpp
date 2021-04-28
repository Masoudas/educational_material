/**
 * The new operator takes a type and returns a pointer to that type, created on the heap. This
 * memory is not initialized, unless we initialize it (for example in the new operator using the bracket
 * operator).
 * 
 * Often, we want to create objects independently of the scope they're defined in. 
 * This can be done using new. These objects are said to be on the heap, or free store,
 * or dynamic memory.
 * 
 * Note that new throws bad_alloc exception if memory does not exist.
 * 
 * Also don't forget that Dynamically allocating arrays is required when your dimensions are given at runtime.
 * As we remember, for example the array size on the stack must be a constant (or constant expression?).
 * (Memory allocated to pointer is stored on the heap).
 * 
 * How does one create the built-in types on the heap? Using the new operator
 * hence an expression like this:
 * int* ptr = new int; 
 * 
 * Note CAREFULLY that that the first expression is pointer, and second is a type. Also note that
 * new int* returns a pointer to pointer to ints!!!
 * With this memory allocation, the memory is not initialized. We can use the following notation however
 * to initialize it:
 * 
 * int* ptr1 = new int{};
 * 
 * Note that we would use the default constructor if the type is user defined.
 * 
 * Naturally, we can use auto in this situation as well.
 */
#include <iostream>
int using_new(){
    auto p = new int;   // Uninitialized
    *p = 7;    

    auto p1 = new int{};    // Initialized
    std::cout << *p1;   // prints zero.
    return *p;
}

