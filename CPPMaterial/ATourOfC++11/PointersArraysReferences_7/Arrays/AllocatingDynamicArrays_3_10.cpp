/**
 * The difference between dynamic array allocation and automatic array allocation is that
 * here we're actually dealing with pointer to pointers.
 * 
 * To create T[][]... in heap, we need to create an array of T* (which is a pointer to pointer or T**)
 * and the allocate each individual  T*.
 * 
 * To delete such array, we have to first delete each T*, and then delete the pointer to pointer array.
 * 
 * Pros: We create an n-d array this way
 * Cons: Because the memory buffer is not contiguous (each subarray is located somewhere), these arrays 
 * are slower than normal array.
 * 
 * Suggestion: Create a 1D array of your total size, and use indexing like T[x  + dim1*y].
 */
#include <iostream>
using namespace std;
void creating_2d_array(){
    // Creating a 3*4 array. Note that the second dimension does not have to 4. This could be a jagged array.
    int** a2d = new int*[2];

    // Initializing the internal 1D array.
    // Question: Could I have used sizeof here? No. Because int* is a dynamic array and decays to pointer, hence
    // we can't use size of. It will always return 4 in my 32 bit machine.
    for (int i = 0; i < 3; i++)
    {
        *(a2d + i) = new int[6];
    }

    *(*(a2d)) = 1;  // Setting the first element to one.
    *(*(a2d) + 1) = 2;  // Setting the second element to two.
    
    cout << "a2d[0][1] is: " << a2d[0][1];

    // Now, to destruct this array, we need to first destruct the int pointers allocated in memory, then destroy
    // the a2d array itself.
    for (int i = 0; i < 3; i++)
    {
        delete[] a2d[i];
    }
    
    delete[] a2d;
    
}

void a1dFora2d(){
    int* a1d = new int[4];

    // Equivalent of accessing a[0][0]
    a1d[0 + 0 * 2] = 0;

    // Equivalent of accessing a[1][0]
    a1d[0 + 1 * 2] = 0;
}