#include <iostream>

/* What is printed according to the standard is:
2 + (-10), where 2 is a char = -8
2 + (-10), where 2 is unsigned = 4294967288
- 10 - 2.12 = -12.12
Pointer addition examples : bdda
Pointer difference : 3
*/
void binary_addition()
{
    char c = 2; // Implicit conversion from int to char (since c++20, module 2^n)
    unsigned int un = 2;    // Implicit conversion to unsigned (2^n).
    int  n = -10;   // -1 * 10 = int times int = int

    std::cout <<  " 2 + (-10), where 2 is a char    = " << c + n << '\n'    // Different signdness. Promoted to unsigned.
              <<  " 2 + (-10), where 2 is unsigned  = " << un + n << '\n'   // Different signdness. Promoted to unsigned. Result
                                                                            // very large.
              <<  " -10 - 2.12  = " << n - 2.12 << '\n';    // Promotion to float.
 
    char a[4] = {'a', 'b', 'c', 'd'};
    char* p = &a[1];
    std::cout << "Pointer addition examples: " << *p << *(p + 2)    
              << *(2 + p) << *(p - 1) << '\n';
    char* p2 = &a[4];
    std::cout << "Pointer difference: " << p2 - p << '\n';
}

???