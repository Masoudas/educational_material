/**
* We normally hear a lot about small string optimization. Here's what it is, according to the web:
* 
* Operations on automatic variables ("from the stack", which are variables that you create without calling 
* malloc / new) are generally much faster than those involving the free store ("the heap", which are variables 
* that are created using new). However, the size of automatic arrays is fixed at compile time, but the size of 
* arrays from the free store is not. Moreover, the stack size is limited (typically a few MiB), whereas the 
* free store is only limited by your system's memory.
* 
* SSO is the Short / Small String Optimization. A std::string typically stores the string as a pointer to the 
* free store ("the heap"), which gives similar performance characteristics as if you were to call 
* new char [size]. This prevents a stack overflow for very large strings, but it can be slower, especially 
* with copy operations. As an optimization, many implementations of std::string create a small automatic 
* array, something like char [20]. If you have a string that is 20 characters or smaller (given this example, 
* the actual size varies), it stores it directly in that array. This avoids the need to call new at all, 
* which speeds things up a bit.
* 
* A schematic of the implementation look something like this:

class string {
public:
    // all 83 member functions
private:
    size_type m_size;
    union {
        class {
            // This is probably better designed as an array-like class
            std::unique_ptr<char[]> m_data;
            size_type m_capacity;
        } m_large;
        std::array<char, sizeof(m_large)> m_small;
    };
};

*/