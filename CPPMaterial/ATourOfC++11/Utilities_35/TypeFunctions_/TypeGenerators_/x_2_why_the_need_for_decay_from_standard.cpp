/**
* The standard gives us an important illustrating point as to why decay_t is needed. Suppose that we want
* to check whether two types are equivalent, but one may be lvalue, rvalue, or has cv-qualifiers (me: note 
* that cv is a 'qualifier'. It's not part of the type, but it attaches itself to it.) The way we can 
* implement it is through using decay to remove any garbage attached to the type, and checking for equivalency.
* 
* This is illustrated in the following example. Note that we first extend the struct std::is_same to determine
* whether two types are the same or not. But, because we may pass the first template argument with cv-qualifiers
* or references or static arrays, we use the decay_t.
*/
#include <iostream>
#include <type_traits>


template<typename U, typename V>
struct decay_equiv : std::is_same<typename std::decay_t<U>, V>::type {};	// Note that we inherit from type.
                                                                           

void checking_equivalency()
{
    std::cout << std::boolalpha     // To print true or false rather than zero and one.
        << decay_equiv<int, int>::value << '\n'
        << decay_equiv<int&, int>::value << '\n'
        << decay_equiv<int&&, int>::value << '\n'
        << decay_equiv<const int&, int>::value << '\n'
        << decay_equiv<int[2], int*>::value << '\n'
        << decay_equiv<int(int), int(*)(int)>::value << '\n';

    
}
