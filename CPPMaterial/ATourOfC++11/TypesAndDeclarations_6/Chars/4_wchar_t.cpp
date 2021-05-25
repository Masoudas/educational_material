/**
 * wchar_t: A character set that is usually large enough to hold the entire char set of the locale. It
 * is large enough to hold UNICODE. It's a distinct type and not defined in any header.
 */
#include <iostream>
using namespace std;

void wchar_t_is_unsigned(){
    // wchar_t is an unsigned entity, hence negative values underflow.
    wchar_t d {'\0'};
    d--;
  //  cout << d;
}
 