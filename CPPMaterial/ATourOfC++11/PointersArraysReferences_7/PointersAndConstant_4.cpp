/**
 * As we know:
 * constexpr: Is used for evaluating constants at compile time.
 * const: Do not change in this scope.
 * 
 * const primary role is to indicate immutability in expressions. Declaring something 
 * constant ensures that it's value is not changed in this scope (in which it was declared
 * constant.) (Me: So I assume that a constant value that is declared in one scope can be changed in
 * another? Not exactly I guess. Because below a is outside the scope, but can't be changed inside)
 */ 
const int a {10};
 void pointers_and_constants(){
     // a = 5; Not possible
     const int p {1};
     const int p1[] = {1,2};  // What is constant here? Note that there's no copy assignment for arrays.
                            // So p1 = {3,4} later on, so I assume that it's not p1. Hence, it must be the content of 
                            // the array.
 }

/**
 * With pointers, it depends where pointer and const are placed relative to one another. The rules described in
 * mixingPointersWithBracket_3_1 is enough for here too ( *const means constant pointer and const * means pointer to const)
 * const int *p;    // p is a pointer to constant int;
 * int const *p;    // p is a pointer to constant int;
 * int *const p;    // p is a constant pointer to int;
 * int const *const p;    // p is a constant pointer to constant int;
 */

/**
 * You can assign the address of a non-constant to a pointer to constant, but not vice versa.
 */

// One challenge with passing by pointer is who's responsible for deleting the object.
void confused(int *p){
    // should p be deleted?
}

void making_a_point(){
    int a[] = {1, 2, 3}; // allocated on stack.
    int* b = new int{7};   // Allocated on heap.

    confused(a); // This would result in a run-time error.
    confused(b); // Did we want to delete this?
}