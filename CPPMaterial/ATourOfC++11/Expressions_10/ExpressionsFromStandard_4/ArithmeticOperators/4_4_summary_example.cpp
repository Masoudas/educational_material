#include <iostream>

/** Here's what's printed:

2 * (-10), where 2 is a char    = -20
2 * (-10), where 2 is unsigned  = 4294967276
-10 / 2.12  = -4.71698
-10 / 21  = 0
-10 % 21  = -10

*/
void binary_mul_div_rem()
{
    char c = 2;
    unsigned int un = 2;
    int  n = -10;
    std::cout << "2 * (-10), where 2 is a char    = " << c * n << '\n'
        << "2 * (-10), where 2 is unsigned  = " << un * n << '\n'
        << "-10 / 2.12  = " << n / 2.12 << '\n'
        << "-10 / 21  = " << n / 21 << '\n'
        << "-10 % 21  = " << n % 21 << '\n';
}