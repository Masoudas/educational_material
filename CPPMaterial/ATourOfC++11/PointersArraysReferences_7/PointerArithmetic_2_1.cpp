/**
 * Pointer arithmetic like everything else is nuanced in c++. It is true that for example int* p,
 * then p++ would increase p by one in terms of int pointer (printing (p+1) - p would yield one). However,
 * if we look at the individual value of each pointer, we see that p++ has increased by 4. Why?
 * Because a pointer looks at the memory address, and the memory address is expressed in terms of a constant unit,
 * which is 32 bits or 64 bits, each of which representing a char (8 bits of space). We can't violate this
 * principle when dealing with pointers, hence say p is at place 1, then p++ is at place 5, because every int is 4 chars
 * in my windows machine. However, when saying p+1 - p, we're actually having an implicit conversion to int, hence, we're increasing
 * one unit in terms of integer memory. These two will not be confused.
 */
#include <iostream>

using namespace std;
void checking_pointer_arithmetic(){
    int* p1 = new int{2};
    
    cout << "Pointer initial location is: " << p1 << endl;
    
    // Now p + 1 would point to the next integer in the memory. But by how much does the value increase? One?
    int* p2 = p1;
    p1++;
    cout << "Pointer augmented by one location is: " << p1 << " which is 4 places higher than the previous"<< endl;
    cout << "However, subtracing pointers lead to 1, as we expect: " << p1 - p2 << " which is why we can do pointer math with arrays";

    
}