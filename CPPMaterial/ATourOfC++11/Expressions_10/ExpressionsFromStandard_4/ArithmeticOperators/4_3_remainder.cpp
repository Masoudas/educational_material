/**
* The binary operator % yields the remainder of the integer division of the first operand by the second (after 
* usual arithmetic conversions; note that the operand types must be integral types). If the quotient a/b is 
* representable in the result type, (a/b)*b + a%b == a. If the second operand is zero, the behavior is 
* undefined. If the quotient a/b is not representable in the result type, the behavior of both a/b and a%b is 
* undefined (that means INT_MIN%-1 is undefined on 2's complement systems)
* 
* Me: The latter is the case because -1 divided by INT_MIN represents not INT_MAX, but INT_MAX plus one, which
* is zero in two's complement system. As such, the operation a - a / b is undefined. Jesus! One needs to pay
* attention to these corner cases. Essentially, 
* 
* Note: Until C++11, if one or both operands to binary operator % were negative, the sign of the remainder was 
* implementation-defined, as it depends on the rounding direction of integer division. The function 
* std::div provided well-defined behavior in that case.
* 
* Note: see std::remainder and std::fmod in the cmath header provide ways of calculating mod ops with respect
* to floating points.
*/

