/**
 * As we aleady know, the string is implemented on a templated type. Bjarne says: 
 * "However, efficiency can be improved and implementations can be simplified for 
 * types that don’t have user-defined copy operations. Consequently, the standard string requires that
 * a type used as its character type be a POD".
 * 
 * There's a template called char_traits:
 * template<typename C> struct char_traits { };
 * 
 * Apparently, the properties of each char set is defined using this template.  Hence, each implementation for each
 * type (char, wchar_t) provide a set of static methods for properties of that char set. So let's say we want
 * a string which is case insensitive, we need to find the proper char_traits and use it as the template parameter of the base_string
 * class. See below for an example.
 * 
 * For example, for char we have:
 * template<>
        struct char_traits<char> { // char_traits operations should not throw exceptions
        using char_type = char;
        using int_type = int; // type of integer value of character
        using off_type = streamoff; // offset in stream
        using pos_type = streampos; // position in stream
        using state_type = mbstate_t; // multibyte stream state
        // ...
    };

    The iso standard of C++, provides four char_traits:
    template<> struct char_traits<char>;
    template<> struct char_traits<char16_t>;
    template<> struct char_traits<char32_t>;
    template<> struct char_traits<wchar_t>;

    And we have the following list of functions inside these char traits:

    c=to_char_type(i):   int_type to char_type conversion
    i=to_int_type(c):    char_type to int_type conversion
    eq_int_type(c,c2):   to_int_type(c)==to_int_type(c2)
    eq(c,c2):            Is c treated as equal to c2?
    lt(c,c2):            Is c treated as less than c2?
    i=compare(p,p2,n):   Lexicographical compare of [p:p+n) and [p2:p2+n)
    assign(c,c2):        c=c2 for char_type
    p2=assign(p,n,c):    Assign n copies of c to [p:p+n); p2=p
    p3=move(p,p2,n):     Copy [p:p+n) to [p2:p2+n); [p:p+n) and [p2:p2+n) may overlap; p3=p
    p3=copy(p,p2,n):     Copy [p:p+n) to [p2:p2+n); [p:p+n) and [p2:p2+n) may not overlap; p3=p. 
                         Because copy() does not protect against overlapping ranges, it may be faster than move().
    n=length(p)          n is the number of characters in [p:q) where ∗q is the first element so that eq(q,charT{})
    p2=find(p,n,c)       p points to the first occurrence of c in [p:p+n) or nullptr
    i=eof()              i is the int_type value representing end-of-file
    i=not_eof(i)         i if !eq_int_type(i,eof()); otherwise i can be any value not equal to eof()

Comparing with eq() is often not simply an ==. For example, a case-insensitive char_traits would
define its eq() so that eq('b','B') would return true. Hence, == is more specialized (comapres exactly), whereas
eq can be more generic.
*/

/*
    Below, we implement a char_traits for char, which is case insensitive.
*/
#include <string>
#include <iostream>

struct ci_char_traits : public std::char_traits<char> {
    static bool eq(char c1, char c2) { return toupper(c1) == toupper(c2); }
    static bool ne(char c1, char c2) { return toupper(c1) != toupper(c2); }
    static bool lt(char c1, char c2) { return toupper(c1) <  toupper(c2); }
    static int compare(const char* s1, const char* s2, size_t n) {
        while( n-- != 0 ) {
            if( toupper(*s1) < toupper(*s2) ) return -1;
            if( toupper(*s1) > toupper(*s2) ) return 1;
            ++s1; ++s2;
        }
        return 0;
    }
    static const char* find(const char* s, int n, char a) {
        while( n-- > 0 && toupper(*s) != toupper(a) ) {
            ++s;
        }
        return s;
    }
};

typedef std::basic_string<char, ci_char_traits> ci_string;

namespace CharacterTraits {
    void char_traits_for_string_comparison() {
        ci_string s1 = "HELLO WORLD!";
        ci_string s2 = "hello world!";

        if (s1 == s2) {
            std::cout << "Strings are case-insensitively equal." << std::endl;
        }

        const char* str1 = "THIS";
        const char* str2 = "this";
    }
}


