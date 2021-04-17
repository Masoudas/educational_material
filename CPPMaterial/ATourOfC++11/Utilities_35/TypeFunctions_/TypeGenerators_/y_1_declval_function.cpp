/**
* Me: See the next file to understand when decltype is useful. The following is from the standard. In short,
* creates a temporary (rvalue) of the object in memory without going through its constructor, making it
* possible for us to use it without constructing it.
* 
* template<class T>
* typename std::add_rvalue_reference<T>::type declval() noexcept
* 
* Converts any type T to a reference type, making it possible to use member functions in decltype expressions 
* without the need to go through constructors.
* 
* declval is commonly used in templates where acceptable template parameters may have no constructor in common, 
* but have the same member function whose return type is needed.
* 
* Note that declval can only be used in unevaluated contexts and is not required to be defined; it is an 
* error to evaluate an expression that contains this function. Formally, the program is ill-formed if this 
* function is odr-used.
* 
* Return value:
* Cannot be called and thus never returns a value. The return type is T&& unless T is (possibly cv-qualified) 
* void, in which case the return type is T.
* 
*/
#include <utility>
#include <iostream>
 
struct Default { int foo() const { return 1; } };
 
struct NonDefault
{
    NonDefault() = delete;
    int foo() const { return 1; }
};
 
void using_declval_function(){
    decltype(Default().foo()) n1 = 1;                   // type of n1 is int
//  decltype(NonDefault().foo()) n2 = n1;               // error: no default constructor
    decltype(std::declval<NonDefault>().foo()) n2 = n1; // type of n2 is int
    std::cout << "n1 = " << n1 << '\n'
              << "n2 = " << n2 << '\n';
}

//int main() {
//    using_decl_type()
//}