/**
* Me: Note that in the standard we talk about std::size_t, which is in cstddef and many other headers. That
* being said, we can use it as a free type from observation.
* 
* The standard says: 
* 
* std::size_t is the unsigned integer type of the result of the sizeof operator as well as the sizeof... 
* operator and the alignof operator (since C++11). The bit width of std::size_t is not less than 16.
* 
* std::size_t can store the maximum size of a theoretically possible object of any type (including array). A 
* type whose size cannot be represented by std::size_t is ill-formed (since C++14) On many platforms 
* (an exception is systems with segmented addressing) std::size_t can safely store the value of any 
* non-member pointer, in which case it is synonymous with std::uintptr_t.
* 
* std::size_t is commonly used for array indexing and loop counting. Programs that use other types, such as
* unsigned int, for array indexing may fail on, e.g. 64-bit systems when the index exceeds UINT_MAX or if 
* it relies on 32-bit modular arithmetic.
* 
* When indexing C++ containers, such as std::string, std::vector, etc, the appropriate type is the member 
* typedef size_type provided by such containers. It is usually defined as a synonym for std::size_t.
*/
