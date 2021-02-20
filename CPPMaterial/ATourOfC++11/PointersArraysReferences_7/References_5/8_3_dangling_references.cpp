/**
* From the standard:
* Although references, once initialized, always refer to valid objects or functions, it is possible to create a 
* program where the lifetime of the referred-to object ends, but the reference remains accessible (dangling). 
* Accessing such a reference is undefined behavior. A common example is a function returning a reference to an 
* automatic variable:
* 
* Note that rvalue references and lvalue references to const extend the lifetimes of temporary objects 
* If the referred-to object was destroyed (e.g. by explicit destructor call), but the storage was not deallocated, 
* a reference to the out-of-lifetime object may be used in limited ways, and may become valid if the object is 
* recreated in the same storage.
* 
* As we may have already encountered, dangling references can happen with rvalue references too. For example,
* if we create an rvalue inside a function and then try and return it with rvalue ref, we get a dangling ref too.
*/
#include <string>
#include <iostream>

std::string& f()
{
    std::string s = "Example";
    return s; // exits the scope of s:
              // its destructor is called and its storage deallocated
}

void playing_with_a_dangling_reference() 
{
    std::string& r = f(); // dangling reference
    std::cout << r;       // undefined behavior: reads from a dangling reference
    std::string s = f();  // undefined behavior: copy-initializes from a dangling reference
}

int&& returning_a_dangling_r_value_reference() 
{
    return { 1 }; // This would be a dangling reference!
}