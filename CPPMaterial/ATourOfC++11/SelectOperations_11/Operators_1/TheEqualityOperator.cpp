/**
 * So here's the deal. The equality operator (=) can work like an lvalue if the left side points 
 * to variable (or another lvalue).
 * Hence for example, consider the following:
 */
#include <iostream>

void equality_operator_examples(){
    int a = 5;
    int b = 2 + (a = 6);    // What would be the result of this? It sets a = 6, then adds two to it, hence 8;

    std::cout << b << std::endl;

    if (a = 6) std::cout << b;  // This would be read as set a = 6, then if(a), which would be true, because a is positive.

    if (5 == 6) { std::cout << "Rvalues can be compared as well"; }
}