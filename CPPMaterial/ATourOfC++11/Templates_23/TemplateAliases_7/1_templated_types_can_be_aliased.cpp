/**
* A templated type can be aliased, for some or all of its templates. In general, if we bind all arguments of a 
* template, we get a type, but if we bind only some, we get a template.
* 
* Note that what we get from using in an alias definition is always an alias. That is, when we use the alias, it is 
* completely equivalent to a use of the original template.
* 
* We can't however directly aliases a templated type name, without introducing the templates. This is because (as
* always) THE TEMPLATES ARE PART OF THE CLASS DEFINITON, not separate entities. 
*/
#include <memory>

template<typename T, typename Allocator = std::allocator<T>> 
struct vector{};

//using vec_alis = vector;

using Cvec = vector<char>; // both arguments are bound
Cvec vc = {}; // vc is a vector<char, allocator<char>>

template<typename T>
struct My_alloc {};

template<typename T>
using Vec = vector<T, My_alloc<T>>; // vector using my allocator (2nd argument is bound)

Vec<int> fib = {}; // fib is a vector<int, My_alloc<int>>
