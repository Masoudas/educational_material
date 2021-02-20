/**
 * Note that an arithmetic can be implicitly converted to bool (0 is false, other values are true, including negative ones)
 * 
 * For pointers, we know that null pointer returns false, otherwise we have true.
 * 
 * My God I've been shot. What is this? if (p && 1<p−>count)
 * p is a pointer, if it's not null, the value of count is greater than 1.
 */
#include <iostream>
void showing_any_nonzero_int_is_true(){
    if (-1){
        std:: cout << "Hey" << " Hey" << " Hey";
    }
}
