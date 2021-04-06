/**
* The big guy goes on to demonstrate his frustation with having to scope to type, and says regarding the stack or heap 
* allocator we just implemented that "Note how the implementation details of Obj_holder (as for Int) shine through when we use 
* typename and ::type to extract the member type. This is a consequence of the way the language is specified and used, 
* this is the way template metaprogramming code has been written for the last 15 years, and this is the way it appears in 
* the C++11 standard. I consider it insufferable. It reminds me of the bad old days in C, where every occurrence of a 
* user-defined type had to be prefixed with the struct keyword. By introducing a template alias, we can hide the ::type 
* implementation details and make a type function look much more like a function returning a type (or like a type)."
* Hence, we'd define the alias as follows:

template<typename T>
using Holder = typename Obj_holder<T>::type;

* Note from me: Since C++14, such aliases are appended with _t by the standard, so it would be Obj_holder_t in this example. 
* However, prior to C++14, there were no such aliases in the standard, as the big guy indicates.
* 
*/