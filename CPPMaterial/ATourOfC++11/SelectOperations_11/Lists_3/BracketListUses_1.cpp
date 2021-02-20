/**
 * The bracket is used for initializing all built-in and user types. It also has two other uses:
 * 1- When written as T{...}, defines an object of type T initialized by T{...}
 * 2- When written as {...}, the type must be deduced from the compiler, as seen below.
 * 
 */
#include <iostream>

// struct S { int a, b; };
// struct SS { double a, b; };
// void f(S); // f() takes an S
// void g(S);
// void g(SS); // g() is overloaded

// int main()
// {
//     f({1,2}); // OK: call f(S{1,2})
//     //g({1,2}); // error : ambiguous. (Me: why? Supposedly, both values are read as int, so it should call g(S).)
//     g(S{1,2}); // OK: call g(S)
//     g(SS{1,2}); // OK: call g(SS)

// }

/**
 * Closely associated here is the initializer_list class. It has a template parameter, and it is 
 * constant. Hence, no element can be changed after initial assignment.
 * 
 * As we already remember, for some user defined types, we can use list_initializer to implicitly assign
 * lists in constructor. An example was the vector, where we say:
 * 
 * std::vector<int> vec = {1, 2, 3, 4}; Implicit conversion from initializer list to vector.
 * Also, this expression could be interpreted (by us, and not the compiler) as follows:
 * 
 * const int temp[] = {1, 2, 3, 4};
 * const initializer_list<int> tmp(temp,sizeof(temp)/sizeof(double));
 * std::vec<int> vec(temp);
 * 
 * Just of note here. In the vector example, the list is destroyed once the vector is initialized.
 * 
 */
#include <initializer_list>
int main(){
    std::initializer_list<int> l{1, 2, 3};   // It could be interpreted as const int a[] = {1, 2, 3}
    //*l.begin() = 2; // Wrong. This is a constant;

    int* x = new int[5];
}


