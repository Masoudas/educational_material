/**
 * As we know, new T[] and delete[] T are used for creating and deleting array like objects.
 * 
 * In other words, T[] returns a T* (pointer to array), not pointer to pointer :D
 */
#include <string>

/** Although we should point out that the best way to copy strings, is to just use the 
 * copy constructor of string.*/
void cpy_string(const char* p){
    int n = std::strlen(p);

    char* q = new char[n + 1];
    std::strcpy(p, q);
    //for (int i = 0; i < n; i++) *(q+i) = *(p+i);

    // Easy way!!
    std::string{q};
}

