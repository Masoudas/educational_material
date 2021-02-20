/**
 * 
 * A string literal is a character sequence enclosed in double quation.  It is terminated
 * with the char \0 (zero char), hence, "Bohr" has five chars.
 * 
 * The type of the expression is const char[]. In c and older C++, assigning the
 * literal to non constant pointer was Ok, but this causes subtle errors.
 * Hence, the following errors:
 */ 
#include <iostream>
void f(){
    const char* p = "Plato";    //error, but accepted in pre-C++11-standard code
   // p[4] = 'e';  //error : assignment to const
}

/**
 * A string literal is statically allocated (see Objects_13 of TypesAndDeclarations_6). 
 * Why you ask? To allow an string to be returned by a function!*/
const char* f(int i){
    return "this is not destructed outsize, because it's not a temporary object";
}

/**
 * Whether two string literals that are the same are kept independently or by the same reference
 * (like C# and Java), is totaly implementation dependent. Hence, the following code is machine 
 * dependent.
 */
void another_point(){
    const char* a1 = "Ey";
    const char* a2 = "Ey";

 //   std::cout << a1 == a2; // Machine dependent.
}

/**
 * It's not possible to have a real break in non-raw strings. Hence
 * const char* p = "a
 *                  b"; // is interpreted as "ab"
 * 
 * To make literals neater, we might write:
 * const char* p = "aaaa"
 *                  "bbbb";
 */