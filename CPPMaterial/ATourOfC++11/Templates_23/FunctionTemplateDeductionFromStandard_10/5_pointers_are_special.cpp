/**
* The standard states as an alternative to the aforementiond rules "The transformed A can be another pointer or 
* pointer to member type that can be converted to the deduced A via a qualification conversions or a function 
* pointer conversion (since C++17):"
* 
* This rule in fact does make sense. For example below, P is deduced as int, and not int* naturally, because
* otherwise if T is deduced as int*, then the argument type would be int**, which is impossible!

template<typename T> void f(const T*);
int* p;
f(p); // P = const T*, A = int*:
      // deduced T = int, deduced A = const int*
      // qualification conversion applies (from int* to const int*)

*/
