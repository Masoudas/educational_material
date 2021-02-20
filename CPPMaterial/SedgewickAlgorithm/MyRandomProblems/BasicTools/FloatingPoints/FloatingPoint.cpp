/**
* As we already know, floating points are 32 or 64 bits in IEEE standard, with bits allocated to both
* exponent and base of the scientific notation.
* 
* The point is that 0.3 is equal to 0.3*10e0 perhaps. However, 0.3 has a repetitive representation in
* base2 format. Hence, we cannot have a correct base number, which is why 0.3 + 0.1 is not exactly 0.4
* but rather 0.400000001 for example.
*/