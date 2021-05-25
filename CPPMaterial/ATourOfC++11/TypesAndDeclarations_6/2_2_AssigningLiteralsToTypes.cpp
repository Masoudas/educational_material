/**
 * This could be all wrong, but at least for now it keeps me going!
 * 
 * One thing that I should not forget that assigning literals to a variable is different from
 * when operations are done on a variable. Assignment is just a form of casting!
 * 
 * For example, if I say char c = 255, this is assigning a literal int to a char. Here, a cast from int to
 * char takes place. If char is unsigned, it will be 255, otherwise it will be -1. What about char c = 256.
 * Here, we're not facing overflow, but rather an assignment. The bits are copied one by one, so this would 
 * be zero, regardless of signed or unsigned.
 * 
 * How about char c = 255; c++; Here, we have an overflow, and people say overflow is undefined for signed entities.
 * For unsigneds we know that's not the case.
 * 
 * Note that assignment by variable is also an assignment. Hence, if I say unsigned char c = 255. Then I say,
 * signed char c1{c}, here, we just have a cast from unsigned to signed, which result in -1. 
 * 
 * :D of course the line signed char c1{c} wouldn't work, because it detects the narowing! 
 */
#include <iostream>
using namespace std;
void assigning_literals_to_types(){
    unsigned char c = 255;
    signed char c1 = c;

    cout << (int)c1;
}
 