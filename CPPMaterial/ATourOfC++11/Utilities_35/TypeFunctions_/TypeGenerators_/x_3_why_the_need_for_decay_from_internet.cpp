/**
* Consider the following make_pair function for a pair from C++03:
* 
* template <class T1, class T2> 
* inline pair<T1,T2> make_pair(T1 x, T2 y)
* { 
*    return pair<T1,T2>(x, y); 
* }
* 
* This version works, but is terrible in the sense that everything has to be copied.
* 
* Now, consider defining:
* 
* template <class T1, class T2> 
* inline pair<T1,T2> make_pair(T1& x, T2& y)
* 
* The problem with this version is that if x is for example a C-string literal, we get into trouble or any other
* lvalue, we get into trouble.
* 
* Now consider we used this version:

template <class T1, class T2>
inline std::pair<T1, T2> make_pair(T1&& x, T2&& y)
{
    return std::pair<T1, T2>(x, y);
}

* This version works slightly better. The problem however is that if passed an l-value, then T would be 
* deduced as T& (recall the template deduction rules).
* 
* In particular, suppose we pass a C-Style string literal to this function. Then oddly enough, the type is
* deduced as const char (&)[n] and not const char* (where n is the string length!). Note that we're talking about
* passing by reference here, so what happens is that because we have a forwarding reference, we should deduce
* a reference, hence we must have a reference to an array, which is an array of n chars. I've no idea why the
* literal version is deduced as reference!
* 
* Now, consider implementing make_pair as follows:

template <class T1, class T2>
inline std::pair<std::decay_t<T1>, std::decay_t<T2>> 
make_pair(T1&& x, T2&& y)
{
    return std::pair<std::decay_t<T1>, std::decay_t<T2>>(x, y);
}

* This way, we remove whatever that might get in our way of adding extra references. Thus, what is generated
* is purely the type, without any cv qualifiers or references that may be deduced by template.
* 
*/
#include <tuple>
#include <string>

template <class T1, class T2>
inline std::pair<T1, T2> make_pair(T1&& x, T2&& y)
{
    return std::pair<T1, T2>(x, y);
}

void using_referenced_make_pair() {
    const char s[2] = "a";
    const int i = 1;
    auto p1 = make_pair(s, i); // Seriously, was this the type we were looking for?! const char(&)[2] 

    auto p = make_pair( "a" , 2);  // Why is it deduced as const char(&)[2] once again?
                                                                

    
}