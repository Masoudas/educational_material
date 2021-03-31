/**
 * With arrays, the new operator still returns a pointer, but to the reduced pointer
 * (for example, new int[] is pointer to int, new int[][] is pointer to array). As we already
 * know, this form does not initialize the memory (i.e, everything will be random)
 * 
 * 
 * Can we initialize arrays at the same time we're allocating them on memory?
 * Yes we can. The syntax is T[]{}, where number of elements has to be specified.
 * 
 * For user defined types on the other hand, note that an object (of a class) can never be in an undefined
 * state. It has to always be initialized. Hence, when creating an array, we MUST define a default
 * empty constructor so that it's called by new operator (so that the space it allocates is initialized),
 * like class A below. Otherwise with class B, because it has no such constructor, initialization is impossible.
 * 
 * The problem here is that if base class is abstract, what can we do? Hence, don't use new and array as
 * Bjarne himself says. Use array class.
 */
#include <iostream>

class A{
public:
    int x = 5;
    A(){};
    A(int n) : x{n}{

    };
};

class B{
public:
    int x = 5;
    B(int n) : x(n){

    };
};

void some_examples(){
    int* arr1 = new int[5];

    int (*arr2)[3] = new int[2][3];

    int* arr3 = new int[3]{1, 2, 3};

    int n = 5;
    A* ref = new A[n];  // Again, note that we're just allocating memory here. The content will be random;
    std::cout << ref[0].x << std::endl;

    A* ref1 = new A[n]{A{6}}; // Initialize everything with default constructor. The rest are initalized with default constructor.
    std::cout << ref1[0].x << std::endl;
    std::cout << ref1[3].x;

    // B* ref2 = new B[n]; Can't do this, because there's no default constructor.
}

