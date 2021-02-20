/**
* If a signed number overflows or underflows, the result is undefined. Why?
*/
#include <iostream>
void signed_number_overflow(){
    signed char c = -256;
    c--;

    std::cout << (int)c; // This didn't become 255! at least on this machine.
}