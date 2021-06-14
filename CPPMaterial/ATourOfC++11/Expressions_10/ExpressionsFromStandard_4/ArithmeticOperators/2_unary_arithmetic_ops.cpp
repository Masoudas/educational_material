/**
* The expressions of the form "+ expression	" and "- expression".
* 
*	1) unary plus (promotion).
* For the built-in operator, expression must have arithmetic, unscoped enumeration, or pointer type. Integral promotion is 
* performed on the operand if it has integral or unscoped enumeration type and determines the type of the result. (ME:
* don't forget that assignment is another story. Possibly a 2^n module takes place.)
*	2) unary minus (negation).
* For the built-in operator, expression must have arithmetic or unscoped enumeration type. Integral promotion is performed 
* on the operand and determines the type of the result.
* 
* The built-in unary plus operator returns the value of its operand. The only situation where it is not a no-op is when 
* the operand has integral type or unscoped enumeration type, which is changed by integral promotion, e.g, it converts 
* char to int or if the operand is subject to lvalue-to-rvalue, array-to-pointer, or function-to-pointer conversion.
* 
* The builtin unary minus operator calculates the negative of its promoted operand. For unsigned a, the value of -a is 2b
* -a, where b is the number of bits after promotion.
* 
* In overload resolution against user-defined operators, for every promoted arithmetic type A and for every type T, the 
* following function signatures participate in overload resolution:
* 
* A operator+(A)
* T* operator+(T*)
* A operator-(A)
*/

#include <iostream>
// What this function prints from the standard:
// char: j int : 106
// - 1, where 1 is signed : -1
// - 1, where 1 is unsigned char : -1
// - 1, where 1 is unsigned int : 4294967295
// size of array : 3
// size of pointer : 8
void unary_arithmetic()
{
    char c = 0x6a;  // me: signed int literal, assigned to char
    int n1 = 1;
    unsigned char n2 = 1;   // Me: Recall that a module 2^n takes place.
    unsigned int n3 = 1;
    std::cout << "char: " << c << " int: " << +c << '\n'    // +c returns! Didn't know that. It returns an int.
        << "-1, where 1 is signed: " << -n1 << '\n'         // -1(int) times n1 (int) results in a signed int
        << "-1, where 1 is unsigned char: " << -n2 << '\n';  // -1(uchar) times n2 (unsgined). -1 promoted to int, 
                                                            // then multiplied.  Result is -1
      //  << "-1, where 1 is unsigned int: " << -n3 << '\n';  // -1(int) times uint. -1 promoted to uint, then multiplied,
                                                            // then result is uint (module 2^n). Interesting that MSVC
                                                            // throws an error here!
    char a[3];
    std::cout << "size of array: " << sizeof a << '\n'
        << "size of pointer: " << sizeof +a << '\n';       // Interesting. +a returns +a, which is a pointer. Hence, size
                                                           // of pointer
}