/**
* Me: In this section of the standard, we talk about how to convert cv-qualified pointers. The notations are
* dense, but I just bring the examples, and we better read them from the standard directly:

char** p = 0;
const char** p1 = p; // error: level 2 more cv-qualified but level 1 is not const
const char* const * p2 = p; // OK: level 2 more cv-qualified and const added at level 1
volatile char * const * p3 = p; // OK: level 2 more cv-qual and const added at level 1
volatile const char* const* p4 = p2; // OK: 2 more cv-qual and const was already at 1

double *a[2][3];
double const * const (*ap)[3] = a; // OK
double * const (*ap1)[] = a; // OK since C++20

Note also that:
char** p = 0;
char * const* p1 = p; // OK in C and C++
const char* const * p2 = p; // error in C, OK in C++

*/