/**
 * A string is based on basic_string class. 
 * 
 * The basic_string has three templates: char template, char_traits of that char, and an allocator. 
 * In other words, what char is used, the behavior of those characters (comparison, copy, etc)
 * and how they're allocated is independent of what the string class does.
 * 
 template<typename C, typename Tr = char_traits<C>, typename A = allocator<C>>
    class basic_string {
    public:
        using traits_type = Tr;
        using value_type = typename Tr::char_type;
        using allocator_type = A;
        using size_type = typename allocator_traits<A>::size_type;
        using difference_type = typename allocator_traits<A>::difference_type;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = typename allocator_traits<A>::pointer;
        using const_pointer = typename allocator_traits<A>::const_pointer;
        using iterator =  ... implementation-defined ;
        using const_iterator = .... implementation-defined ;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
        static const size_type npos = −1; // integer representing end-of-string
        // ...
};
*/

/**
 * The elements (characters) are stored contiguously, so that low-level input operations can safely use
a basic_string’s sequence of characters as a source or target.
*/

/**
 * The basic_string offers the strong guarantee (§13.2): if a basic_string operation throws, the
string is left unchanged.*/

/**
 * We have the following specializations of basic_string already implemented.
using string = basic_string<char>;
using u16string = basic_string<char16_t>;
using u32string = basic_string<char32_t>;
using wstring = basic_string<wchar_t>;

*/