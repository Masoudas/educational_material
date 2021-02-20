/**
 * basic_string offers a variety of constructors. The most widely used ones are:
 * 
 * basic_string s{};  // Empty construction.
 * string s1{"From C-Style String"};
 * string s2{s1};   // Copy constructor.
 * 
 * Don't initialize a string with a nullptr.
 */


/**
 * Other versions are:
 * 
 * - basic_string s {x,a}; s gets the characters from x; use allocator a.
 * - basic_string s {s2,pos,n,a}; s gets the characters s2[pos:pos+n); use allocator a. There's also a version without allocator.
 *                                This is one way of getting a substring.
 * - basic_string s {n,c,a}; s holds n copies of the character c; use allocator a
 * - basic_string s {b,e,a}; s gets the characters from [b:e); use allocator a. (Was is das?)
 */
#include <string>
#include <iostream>

using namespace std;

namespace Constructors_3 {
    void getSubstrings() {
        string str = "This is the base string";

        string sub_str1{ str, 0, 4 };   // Starting from position 0, length 4, would be This
        cout << sub_str1 << endl;
    }

    /*
    * Question: The C-Style string is allocated on the stack. Is that not a problem? Normally with such objects, 
    * not unlike vectors, we allocate the internal memory on the heap. In fact, that is why a template parameter is an
    * allocator!
    */
    string* allocate_on_heap() {
        return new string{ "This is allocated on heap" };
    }

    void test_string_basics() {
        string str{ 'a', 'c', 'e' };
        cout << str << endl;

        string str1{ 77, 'a' };    // Bjarne says this should return 7'a's, but in my machine, it returns two chars!
        cout << str1 << endl;

        string str2{ 7, 5 };    // Equivalent chars of 7 and 5.
        cout << str2 << endl;

        getSubstrings();

        string *str_on_heap = allocate_on_heap();
        cout << "String allocated on heap has size: " << str_on_heap->length();

    }
}
