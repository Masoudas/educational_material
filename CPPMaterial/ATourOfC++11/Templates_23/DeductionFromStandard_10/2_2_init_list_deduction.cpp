/**
* Now, let's consider initializer lists, and type deduction. The standard says:
* "If removing references and cv-qualifiers from P gives std::initializer_list<P'> and A is a braced-init-list, 
* then deduction is performed for every element of the initializer list, taking P' as the parameter and the 
* list element A' as the argument."
* 
* Essentially, what this implies is that a templated init_list is deduced with the help of its parameters. The
* template definition the standard has in mind is something like this:
* 
* template<typename T>
* void f(initializer_list<T>);
* 
* This makes sense, because we want the user to supply a list of arguments. In this case, the type T is deduced
* as the rule above stated. It's not talking about something like this:
* 
*/
#include <initializer_list>
 
template<class T> 
void init_lister(std::initializer_list<T>) {}; 

void using_init_lister() {
    init_lister({ 1, 2, 3 });  // P = std::initializer_list<T>, A = {1, 2, 3}
               // P'1 = T, A'1 = 1: deduced T = int
               // P'2 = T, A'2 = 2: deduced T = int
               // P'3 = T, A'3 = 3: deduced T = int
               // OK: deduced T = int
    // init_lister({ 1, "abc" }); // P = std::initializer_list<T>, A = {1, "abc"}
                   // P'1 = T, A'1 = 1: deduced T = int
                   // P'2 = T, A'2 = "abc": deduced T = const char*
                   // error: deduction fails, T is ambiguous
    // init_lister({ 1, 1.1 }); P'1=int, P'2=double -> Error! deduction fails, T is ambiguous.
}

