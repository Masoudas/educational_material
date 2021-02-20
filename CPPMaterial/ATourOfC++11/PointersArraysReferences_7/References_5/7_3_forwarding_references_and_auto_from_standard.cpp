/**
* The following is from the standard.
* 
* Forwarding references are a special kind of references that preserve the value category of a function argument, 
* making it possible to forward it by means of std::forward. Forwarding references are either:
* 
* 1) function parameter of a function template declared as rvalue reference to cv-unqualified type template 
*	parameter of that same function template
* 2) auto&& except when deduced from a brace-enclosed initializer list:
* 
* (Me: See how when we pass an object to a function, it's actually deduced as an lvalue. This is because as
* we said, it's (at least safe) to assume that an object id itself is an lvalue! So, category_1_forwarding(i)
* is in fact category_1_forwarding<int&>(int&&&) = category_1_forwarding<int&>(int&). Ok!!! Moreover, see
* now that the template of std::forward<int&> is in fact int&. So this is the proper function of forwarding.
* Cool!)
* 
* (Me: Notice that because class templated are not deduced, they cannot be forwarded, unless we specify them
* properly! God Almighty! )
*/

#include <vector>

template<class T>
int category1_non_forwarding(const T&& x);

template<class T>
int category_1_forwarding(T&& x) { // x is a forwarding reference
    return category_1_forwarding(std::forward<T>(x)); // and so can be forwarded
    //return category1_non_forwarding(std::forward<T>(x));// Question: I cannot return as such, and it says the 
    // can't cast from int to const T&&! The problem is  actually for when I try to pass i below, and not the 
    // literal 0!
}

template<class T>
int category1_non_forwarding(const T&& x) { return 0; }; // x is not a forwarding reference: const T is not 
                                                         // cv-unqualified. Hence, using forward is pointless!
                                                         // (me: perhaps unless we re-cast to non-const type?)

template<class T> struct A {
    template<class U>
    A(T&& x, U&& y, int* p) {} // x is not a forwarding reference: T is not a
                               // type template parameter of the constructor,                               // but y is a forwarding reference
};

void using_category_1() {
    int i;
    category_1_forwarding(i); // argument is lvalue, calls category_1_forwarding<int&>(int&), 
                              // std::forward<int&>(x) is lvalue
    category_1_forwarding(0); // argument is rvalue, calls f<int>(int&&), std::forward<int>(x) is rvalue
                              // The pitfal was that I for a second assumed the template to be int&&!
                              // So, does forwarding imply a copy here? Interestingly, no! Because the temporary
                              // here is an rvalue! So, another move would take place!
    A<int> a{ 1, 2, &i };   // I guess now it's safe to assume that we're passing an rvalue, and it can be
                            // forwarded!
    A<int&> a_2{ i, 2, &i };    // Again, I guess this is fine too! The problem is that we initialize such a class
                                // wiht an int, rather than int&.
    
}

std::vector<int> returns_a_vector() {
    return {};
}

struct S{};

void category_2_examples(std::vector<int> vec) {
    auto&& vec1 = returns_a_vector();       // foo() may be lvalue or rvalue, vec is a forwarding reference
    auto i = std::begin(vec); // works either way
    (*i)++;                   // works either way
    //g(std::forward<decltype(vec)>(vec)); // forwards, preserving value category. (Me: Note that if had put
                                            // vec directly here, it would have always been an lvalue)

    //for (auto&& x : f()) {
        // Same as auto&& x = *__begin;
        // x is a forwarding reference; this is the safest way to use range for loops
        
        /* Why? I guess, perhaps, if begin returns by, say, creating an object at the point of return, then
        * having an rvalue reference is handy! And actually an lvalue reference throws an error! 
        */
    //}

    auto&& z = { 1, 2, 3 }; // *not* a forwarding reference (special case for initializer lists)
                            // (What does it mean? I have no clue! The type is initializer_list<int>&&.
                            // So then, what's the problem?)
    auto&& k = 1;           // k is an int&& here!
}