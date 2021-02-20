/**
 * If a program is a success, it will be compiled in different machines. Plus, a compiler may
 * change some features from one version to another. Hence, we want to consider the impact of size
 * of variables.
 * 
 * As we know, the size of each object is returned in terms of char. Hence, sizeof(int) == 4
 * means an int is four bytes.
 * 
 * 
 * We always have: 
 * sizeof(char) <= sizeof(short)<= sizeof(int) <= sizeof(long int) <= sizeof(long long int)
 * 1<=sizeof(bool)<=sizeof(long)
 * sizeof(char)<=sizeof(wchar_t)<=sizeof(long)
 * sizeof(float)<=sizeof(double)<=sizeof(long double)
 * sizeof(N) = sizeof (unsigned N) = sizeof(signed N).
 * 
 * (Me: I remember reading somewhere that bool maybe a an int itself. So the second line tries to convey this 
 * info).
 * 
 * In addition, it is GUARANTEED that a char has at least 8 bits, a short at least 16 bits, 
 * and a long at least 32 bits.
 * 
 * Use of limits and sizeof help us determine everything
 * 
 * If a value v can be represented exactly in a variable of type T, a conversion of v to T 
 * is value-preserving. Conversions that are not value-preserving are best avoided.
 * 
 * The standard header<cstddef> defines an alias that is very widely used in both standard-library declarations 
 * and user code: size_t is an implementation-defined unsigned integer type that can hold the size in bytes 
 * of every object. 
 * Consequently, it is used  where  we  need  to  hold  an  object  size.  For example: 
 * void* allocate(size_t n); // get n bytes
 */
#include <limits>
#include <iostream>
using namespace std;

void deriving_limits_using_std_limits(){
    cout << "size of long " << sizeof(1L) << '\n';
    cout << "size of long long " << sizeof(1LL) << '\n';
    cout << "largest float == " << std::numeric_limits<float>::max() << '\n';
    cout << "char is signed == " << std::numeric_limits<char>::is_signed << '\n';
}