/**
 * To summarize, having naked news and deletes is what's causing all the problems.
 * 
 * So, new and delete should not be found nakedly in the code. They should always be in constructors of
 * other classes (mainly smart pointers), or they should be inside constructor and destructors of classes.
 */
#include <memory>
#include <stdexcept>

int main(){
    int n = 3;

    int* p = new int[n];
    std::unique_ptr<int[]> ptr{new int[n]};

    if (n%2) throw std::runtime_error{"Hey!"};
    delete[] p; // This resource is leaked. However, because ptr goes out of scope, its associated memory is deleted.

}