/**
* The following is from the CPP standard, indicating one's complement numbers are not allowed anymore:
* 
* Prior to C++20, the C++ Standard allowed any signed integer representation, and the minimum guaranteed 
* range of N-bit signed integers was from -(2^(N-1)-1) to +2^(N-1)-1 (e.g. -127 to 127 for a signed 8-bit 
* type), which corresponds to the limits of one's complement or sign-and-magnitude.
* 
* However, all C++ compilers use two's complement representation, and as of C++20, it is the only 
* representation allowed by the standard, with the guaranteed range from -2^(N-1) to +2^(N-1)-1 (e.g. -128 
* to 127 for a signed 8-bit type
* 
* 8-bit one's complement and sign-and-magnitude representations for char have been disallowed since C++11.
* 
*/